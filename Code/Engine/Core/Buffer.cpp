#include "Engine/Core/Buffer.hpp"

BufferWriter::BufferWriter(std::vector<uint8_t>& bufferToWrite)
	:m_buffer(bufferToWrite)
{

}

void BufferWriter::AppendByte(uint8_t byteToAppend)
{
	m_buffer.push_back(byteToAppend);
}

void BufferWriter::AppendChar(char charToAppend)
{
	uint8_t* bytes = reinterpret_cast<uint8_t*>(&charToAppend);
	m_buffer.push_back(bytes[0]);
}

void BufferWriter::AppendUshort(unsigned short ushortToAppend)
{
	uint8_t* bytes = reinterpret_cast<uint8_t*>(&ushortToAppend);
	for (size_t i = 0; i < sizeof(unsigned short); ++i)
	{
		AppendByte(bytes[i]);
	}
}

void BufferWriter::AppendShort(signed short shortToAppend)
{
	uint8_t* bytes = reinterpret_cast<uint8_t*>(&shortToAppend);
	for (size_t i = 0; i < sizeof(signed short); ++i)
	{
		AppendByte(bytes[i]);
	}
}

void BufferWriter::AppendUint32(unsigned int uintToAppend)
{
	uint8_t* bytes = reinterpret_cast<uint8_t*>(&uintToAppend);
	for (size_t i = 0; i < sizeof(unsigned int); ++i)
	{
		AppendByte(bytes[i]);
	}
}

void BufferWriter::AppendInt32(signed int intToAppend)
{
	uint8_t* bytes = reinterpret_cast<uint8_t*>(&intToAppend);
	for (size_t i = 0; i < sizeof(signed int); ++i)
	{
		AppendByte(bytes[i]);
	}
}

void BufferWriter::AppendUint64(uint64_t uintToAppend)
{
	uint8_t* bytes = reinterpret_cast<uint8_t*>(&uintToAppend);
	for (size_t i = 0; i < sizeof(uint64_t); ++i)
	{
		AppendByte(bytes[i]);
	}
}

void BufferWriter::AppendInt64(int64_t intToAppend)
{
	uint8_t* bytes = reinterpret_cast<uint8_t*>(&intToAppend);
	for (size_t i = 0; i < sizeof(uint8_t); ++i)
	{
		AppendByte(bytes[i]);
	}
}

void BufferWriter::AppendFloat(float floatToAppend)
{
	uint8_t* bytes = reinterpret_cast<uint8_t*>(&floatToAppend);
	for (size_t i = 0; i < sizeof(float); ++i)
	{
		AppendByte(bytes[i]);
	}
}

void BufferWriter::AppendDouble(double doubleToAppend)
{
	uint8_t* bytes = reinterpret_cast<uint8_t*>(&doubleToAppend);
	for (size_t i = 0; i < sizeof(double); ++i)
	{
		AppendByte(bytes[i]);
	}
}

void BufferWriter::AppendBool(bool boolToAppend)
{
	AppendByte(boolToAppend ? 1 : 0);
}

void BufferWriter::AppendZeroTerminatedString(std::string const& strToAppend)
{
	for (char c : strToAppend)
	{
		AppendChar(c);
	}
	AppendChar('\0');  // Add the null terminator
}

void BufferWriter::AppendLengthPrecededString(std::string const& strToAppend)
{
	AppendUshort(static_cast<unsigned short>(strToAppend.length()));
	for (char c : strToAppend)
	{
		AppendChar(c);
	}
}

void BufferWriter::AppendVec2(Vec2 const& vecToAppend)
{
	AppendFloat(vecToAppend.x);
	AppendFloat(vecToAppend.y);
}

void BufferWriter::AppendVec3(Vec3 const& vecToAppend)
{
	AppendFloat(vecToAppend.x);
	AppendFloat(vecToAppend.y);
	AppendFloat(vecToAppend.z);
}

void BufferWriter::AppendVec4(Vec4 const& vecToAppend)
{
	AppendFloat(vecToAppend.x);
	AppendFloat(vecToAppend.y);
	AppendFloat(vecToAppend.z);
	AppendFloat(vecToAppend.w);
}

void BufferWriter::AppendIntVec2(IntVec2 const& vecToAppend)
{
	AppendInt32(vecToAppend.x);
	AppendInt32(vecToAppend.y);
}

void BufferWriter::AppendIntVec3(IntVec3 const& vecToAppend)
{
	AppendInt32(vecToAppend.x);
	AppendInt32(vecToAppend.y);
	AppendInt32(vecToAppend.z);
}

void BufferWriter::AppendIntVec4(IntVec4 const& vecToAppend)
{
	AppendInt32(vecToAppend.x);
	AppendInt32(vecToAppend.y);
	AppendInt32(vecToAppend.z);
	AppendInt32(vecToAppend.w);
}

void BufferWriter::AppendRgba8(Rgba8 const colorToAppend)
{
	AppendChar(colorToAppend.r);
	AppendChar(colorToAppend.g);
	AppendChar(colorToAppend.b);
	AppendChar(colorToAppend.a);
}

void BufferWriter::AppendRgb8(Rgba8 const colorToAppend)
{
	AppendChar(colorToAppend.r);
	AppendChar(colorToAppend.g);
	AppendChar(colorToAppend.b);
	AppendChar((unsigned char)255);
}

void BufferWriter::AppendAABB2(AABB2 const& aabb2ToAppend)
{
	AppendVec2(aabb2ToAppend.m_mins);
	AppendVec2(aabb2ToAppend.m_maxs);
}

void BufferWriter::AppendAABB3(AABB3 const& aabb3ToAppend)
{
	AppendVec3(aabb3ToAppend.m_mins);
	AppendVec3(aabb3ToAppend.m_maxs);
}

void BufferWriter::AppendOBB2(OBB2 const& obb2ToAppend)
{
	AppendVec2(obb2ToAppend.m_center);
	AppendVec2(obb2ToAppend.m_halfDimensions);
	AppendVec2(obb2ToAppend.m_iBasisNormal);
}

void BufferWriter::AppendOBB3(OBB3 const& obb3ToAppend)
{
	AppendVec3(obb3ToAppend.m_center);
	AppendVec3(obb3ToAppend.m_halfDimensions);
	AppendVec3(obb3ToAppend.m_iBasisNormal);
	AppendVec3(obb3ToAppend.m_jBasisNormal);
}

void BufferWriter::AppendPlane2(Plane2 const& plane2ToAppend)
{
	AppendVec2(plane2ToAppend.m_normal);
	AppendFloat(plane2ToAppend.m_distanceFromOrigin);
}

void BufferWriter::AppendPlane3(Plane3 const& plane3ToAppend)
{
	AppendVec3(plane3ToAppend.m_normal);
	AppendFloat(plane3ToAppend.m_distanceFromOrigin);
}

void BufferWriter::AppendVertexPCU(Vertex_PCU const& vertToAppend)
{
	AppendVec3(vertToAppend.m_position);
	AppendRgba8(vertToAppend.m_color);
	AppendVec2(vertToAppend.m_uvTexCoords);

}

void BufferWriter::WriteIntToPos(size_t startPos, unsigned int intToWrite)
{
	if (startPos + sizeof(unsigned int) <= m_buffer.size())
	{
		uint8_t* bytes = reinterpret_cast<uint8_t*>(&intToWrite);
		if (m_localEndianMode == m_preferredEndianMode)
		{
			m_buffer[startPos] = bytes[0];
			m_buffer[startPos + 1] = bytes[1];
			m_buffer[startPos + 2] = bytes[2];
			m_buffer[startPos + 3] = bytes[3];
		}
		else
		{
			m_buffer[startPos] = bytes[3];
			m_buffer[startPos + 1] = bytes[2];
			m_buffer[startPos + 2] = bytes[1];
			m_buffer[startPos + 3] = bytes[0];
		}
	}
}

void BufferWriter::SetPreferredEndianMode(EndianMode mode)
{
	m_preferredEndianMode = mode;
}

EndianMode BufferWriter::GetPreferredEndianMode() const
{
	return m_preferredEndianMode;
}

EndianMode BufferWriter::GetLocalEndianMode() const
{
	return m_localEndianMode;
}

size_t BufferWriter::GetCurBufferSize() const
{
	return m_buffer.size();
}

void BufferWriter::SwitchByte(uint8_t* a, uint8_t* b) const
{
	uint8_t temp = *a;
	*a = *b;
	*b = temp;
}

BufferParser::BufferParser(uint8_t const* const& buffer, size_t size)
	:m_buffer(buffer), m_size(size)
{

}

BufferParser::BufferParser(std::vector<uint8_t> const& bufferToRead)
	:m_buffer(bufferToRead.data()), m_size(bufferToRead.size())
{

}

uint8_t BufferParser::ParseByte()
{
	uint8_t byte = m_buffer[m_currentPosition];
	m_currentPosition += sizeof(uint8_t);
	return byte;
}

char BufferParser::ParseChar()
{
	auto* value = reinterpret_cast<char*>(m_buffer[m_currentPosition]);
	m_currentPosition += sizeof(char);
	return *value;
}

unsigned short BufferParser::ParseUshort()
{
	auto* value = reinterpret_cast<unsigned short*>(m_buffer[m_currentPosition]);
	m_currentPosition += sizeof(unsigned short);
	return *value;
}

signed short BufferParser::ParseShort()
{
	auto* value = reinterpret_cast<signed short*>(m_buffer[m_currentPosition]);
	m_currentPosition += sizeof(signed short);
	return *value;
}

unsigned int BufferParser::ParseUint32()
{
	auto* value = reinterpret_cast<unsigned int*>(m_buffer[m_currentPosition]);
	m_currentPosition += sizeof(unsigned int);
	return *value;
}

signed int BufferParser::ParseInt32()
{
	auto* value = reinterpret_cast<signed int*>(m_buffer[m_currentPosition]);
	m_currentPosition += sizeof(signed int);
	return *value;
}

uint64_t BufferParser::ParseUint64()
{
	auto* value = reinterpret_cast<uint64_t*>(m_buffer[m_currentPosition]);
	m_currentPosition += sizeof(uint64_t);
	return *value;
}

int64_t BufferParser::ParseInt64()
{
	auto* value = reinterpret_cast<int64_t*>(m_buffer[m_currentPosition]);
	m_currentPosition += sizeof(int64_t);
	return *value;
}

float BufferParser::ParseFloat()
{
	auto* value = reinterpret_cast<float*>(m_buffer[m_currentPosition]);
	m_currentPosition += sizeof(float);
	return *value;
}

double BufferParser::ParseDouble()
{
	auto* value = reinterpret_cast<double*>(m_buffer[m_currentPosition]);
	m_currentPosition += sizeof(double);
	return *value;
}

bool BufferParser::ParseBool()
{
	uint8_t byte = m_buffer[m_currentPosition];
	return (byte == 1) ? true : false;
}

void BufferParser::ParseZeroTerminatedString(std::string& str)
{
	while (m_buffer[m_currentPosition] != '\0')
	{
		char character = ParseChar();
		str.push_back(character);
	}
	ParseChar();
}

void BufferParser::ParseLengthPrecededString(std::string& str)
{
	uint32_t stringLength = ParseUint32();

	for (int i = 0; i < stringLength; i++)
	{
		char character = ParseChar();
		str.push_back(character);
	}
}

Vec2 BufferParser::ParseVec2()
{
	Vec2 value;
	value.x = ParseFloat();
	value.y = ParseFloat();
	return value;
}

Vec3 BufferParser::ParseVec3()
{
	Vec3 value;
	value.x = ParseFloat();
	value.y = ParseFloat();
	value.z = ParseFloat();
	return value;
}

Vec4 BufferParser::ParseVec4()
{
	Vec4 value;
	value.x = ParseFloat();
	value.y = ParseFloat();
	value.z = ParseFloat();
	value.w = ParseFloat();
	return value;
}

IntVec2 BufferParser::ParseIntVec2()
{
	IntVec2 value;
	value.x = ParseUint32();
	value.y = ParseUint32();
	return value;
}

IntVec3 BufferParser::ParseIntVec3()
{
	IntVec3 value;
	value.x = ParseUint32();
	value.y = ParseUint32();
	value.z = ParseUint32();
	return value;
}

IntVec4 BufferParser::ParseIntVec4()
{
	IntVec4 value;
	value.x = ParseUint32();
	value.y = ParseUint32();
	value.z = ParseUint32();
	value.w = ParseUint32();
	return value;
}

Rgba8 BufferParser::ParseRgba8()
{
	Rgba8 value;
	value.r = ParseChar();
	value.g = ParseChar();
	value.b = ParseChar();
	value.a = ParseChar();
	return value;
}

Rgba8 BufferParser::ParseRgb8()
{
	Rgba8 value;
	value.r = ParseChar();
	value.g = ParseChar();
	value.b = ParseChar();
	value.a = 255;
	return value;
}

AABB2 BufferParser::ParseAABB2()
{
	AABB2 value;
	value.m_mins = ParseVec2();
	value.m_maxs = ParseVec2();
	return value;
}

AABB3 BufferParser::ParseAABB3()
{
	AABB3 value;
	value.m_mins = ParseVec3();
	value.m_maxs = ParseVec3();
	return value;
}

OBB2 BufferParser::ParseOBB2()
{
	OBB2 value;
	value.m_center = ParseVec2();
	value.m_halfDimensions = ParseVec2();
	value.m_iBasisNormal = ParseVec2();
	return value;
}

OBB3 BufferParser::ParseOBB3()
{
	OBB3 value;
	value.m_center = ParseVec3();
	value.m_halfDimensions = ParseVec3();
	value.m_iBasisNormal = ParseVec3();
	value.m_jBasisNormal = ParseVec3();
	return value;
}

Plane2 BufferParser::ParsePlane2()
{
	Plane2 value;
	value.m_normal = ParseVec2();
	value.m_distanceFromOrigin = ParseFloat();
}

Plane3 BufferParser::ParsePlane3()
{
	Plane3 value;
	value.m_normal = ParseVec3();
	value.m_distanceFromOrigin = ParseFloat();
}

Vertex_PCU BufferParser::ParseVertexPCU()
{
	Vertex_PCU value;
	value.m_position = ParseVec3();
	value.m_color = ParseRgba8();
	value.m_uvTexCoords = ParseVec2();
	return value;
}

size_t BufferParser::GetCurReadPosition() const
{
	return m_currentPosition;
}

void BufferParser::SetCurReadPosition(size_t readPosition)
{
	m_currentPosition = readPosition;
}

void BufferParser::SetBufferEndianMode(EndianMode mode)
{
	m_bufferEndianMode = mode;
}

EndianMode BufferParser::GetBufferEndianMode() const
{
	return m_bufferEndianMode;
}

EndianMode BufferParser::GetLocalEndianMode() const
{
	return m_localEndianMode;
}

void BufferParser::SwitchByte(uint8_t* a, uint8_t* b) const
{
	uint8_t temp = *a;
	*a = *b;
	*b = temp;
}

bool BufferParser::SafetyCheck(size_t steps) const
{

}
