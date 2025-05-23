#pragma once
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <vector>
#include <atomic>
#include <future>
#include <type_traits> 

enum class JobState
{
	NEW,
	QUEUED,
	EXECUTING,
	COMPLETED,
	RETRIEVED
};
struct JobSystemConfig
{
	int m_numWorkers = -1;
};

struct Job
{
	Job() = default;
	virtual ~Job() = default;

	virtual void Execute() = 0;
	std::atomic<unsigned int> m_Bitflags = 1;
	std::atomic<JobState> m_state = JobState::NEW;
};


class JobWorker
{
	friend class JobSystem;

	JobWorker(int id, JobSystem* system);
	~JobWorker();

	void ThreadMain();

public:
	void Join();

private:
	int m_id = -1;
	std::atomic<unsigned int> m_jobTypeBitflags = 1;
	JobSystem* m_system = nullptr;
	std::thread* m_thread = nullptr;
};

class JobSystem
{
	friend class JobWorker;

public:
	JobSystem(JobSystemConfig config);

	void Startup();
	void BeginFrame();
	void EndFrame();
	void Shutdown();

	JobSystemConfig m_config;

	void CreateWorkers(int num);
	JobWorker* GetWorker(int id);
	void DestroyWorkers();
	size_t GetWorkersSize() const;
	void QueueJob(Job* jobToQueue);
	Job* ClaimJob(JobWorker* worker);
	void CompleteJob(Job* jobToComplete);
	Job* RetrieveJob(Job* jobToRetrived = nullptr);
	size_t GetNumQueuedJobs() const;
	size_t GetNumCompletedJobs() const;

	void ClearAllJobs();
	void SetWorkerThreadJobFlags(unsigned int bitflags, int num);
	void SetWorkerThreadIDJobFlags(unsigned int bitflags, int id);

private:
	std::vector<JobWorker*> m_workers;
	std::deque<Job*> m_queuedJobs;
	std::deque<Job*> m_executingJobs;
	std::deque<Job*> m_completedJobs;
	mutable std::mutex m_queuedJobsMutex;
	mutable std::mutex m_executingJobsMutex;
	mutable std::mutex m_completedJobsMutex;
	std::atomic<bool> m_isShuttingDown = false;
};