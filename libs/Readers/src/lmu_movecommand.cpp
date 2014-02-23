/*
 * This file is part of EasyRPG.
 *
 * EasyRPG is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
 */

// Headers
#include "rpg_movecommand.h"
#include "reader_struct.h"

template <>
struct RawStruct<RPG::MoveCommand> {
	static void ReadLcf(RPG::MoveCommand& ref, LcfReader& stream, uint32_t length);
	static void WriteLcf(const RPG::MoveCommand& ref, LcfWriter& stream);
	static int LcfSize(const RPG::MoveCommand& ref, LcfWriter& stream);
	static void WriteXml(const RPG::MoveCommand& ref, XmlWriter& stream);
	static void BeginXml(RPG::MoveCommand& ref, XmlReader& stream);
};

template <>
struct RawStruct<std::vector<RPG::MoveCommand> > {
	static void ReadLcf(std::vector<RPG::MoveCommand>& ref, LcfReader& stream, uint32_t length);
	static void WriteLcf(const std::vector<RPG::MoveCommand>& ref, LcfWriter& stream);
	static int LcfSize(const std::vector<RPG::MoveCommand>& ref, LcfWriter& stream);
	static void WriteXml(const std::vector<RPG::MoveCommand>& ref, XmlWriter& stream);
	static void BeginXml(std::vector<RPG::MoveCommand>& ref, XmlReader& stream);
};

/**
 * Reads Move Command.
 */
void RawStruct<RPG::MoveCommand>::ReadLcf(RPG::MoveCommand& ref, LcfReader& stream, uint32_t /* length */) {
	ref.command_id = stream.ReadInt();
	switch (ref.command_id) {
		case RPG::MoveCommand::Code::switch_on:
			stream.Read(ref.parameter_a);
			break;
		case RPG::MoveCommand::Code::switch_off:
			stream.Read(ref.parameter_a);
			break;
		case RPG::MoveCommand::Code::change_graphic:
			stream.ReadString(ref.parameter_string, stream.ReadInt());
			stream.Read(ref.parameter_a);
			break;
		case RPG::MoveCommand::Code::play_sound_effect:
			stream.ReadString(ref.parameter_string, stream.ReadInt());
			stream.Read(ref.parameter_a);
			stream.Read(ref.parameter_b);
			stream.Read(ref.parameter_c);
			break;
	}
}

void RawStruct<RPG::MoveCommand>::WriteLcf(const RPG::MoveCommand& ref, LcfWriter& stream) {
	stream.WriteInt(ref.command_id);
	switch (ref.command_id) {
		case RPG::MoveCommand::Code::switch_on:
			stream.Write(ref.parameter_a);
			break;
		case RPG::MoveCommand::Code::switch_off:
			stream.Write(ref.parameter_a);
			break;
		case RPG::MoveCommand::Code::change_graphic:
			stream.WriteInt(stream.Decode(ref.parameter_string).size());
			stream.Write(ref.parameter_string);
			stream.Write(ref.parameter_a);
			break;
		case RPG::MoveCommand::Code::play_sound_effect:
			stream.WriteInt(stream.Decode(ref.parameter_string).size());
			stream.Write(ref.parameter_string);
			stream.Write(ref.parameter_a);
			stream.Write(ref.parameter_b);
			stream.Write(ref.parameter_c);
			break;
	}
}

int RawStruct<RPG::MoveCommand>::LcfSize(const RPG::MoveCommand& ref, LcfWriter& stream) {
	int result = 0;
	result += LcfReader::IntSize(ref.command_id);
	switch (ref.command_id) {
		case RPG::MoveCommand::Code::switch_on:
			result += LcfReader::IntSize(ref.parameter_a);
			break;
		case RPG::MoveCommand::Code::switch_off:
			result += LcfReader::IntSize(ref.parameter_a);
			break;
		case RPG::MoveCommand::Code::change_graphic:
			result += LcfReader::IntSize(stream.Decode(ref.parameter_string).size());
			result += stream.Decode(ref.parameter_string).size();
			result += LcfReader::IntSize(ref.parameter_a);
			break;
		case RPG::MoveCommand::Code::play_sound_effect:
			result += LcfReader::IntSize(stream.Decode(ref.parameter_string).size());
			result += stream.Decode(ref.parameter_string).size();
			result += LcfReader::IntSize(ref.parameter_a);
			result += LcfReader::IntSize(ref.parameter_b);
			result += LcfReader::IntSize(ref.parameter_c);
			break;
	}
	return result;
}

void RawStruct<RPG::MoveCommand>::WriteXml(const RPG::MoveCommand& ref, XmlWriter& stream) {
	stream.BeginElement("MoveCommand");
	stream.WriteNode<int>("command_id", ref.command_id);
	switch (ref.command_id) {
		case RPG::MoveCommand::Code::switch_on:
			stream.WriteNode<int>("parameter_a", ref.parameter_a);
			break;
		case RPG::MoveCommand::Code::switch_off:
			stream.WriteNode<int>("parameter_a", ref.parameter_a);
			break;
		case RPG::MoveCommand::Code::change_graphic:
			stream.WriteNode<std::string>("parameter_string", ref.parameter_string);
			stream.WriteNode<int>("parameter_a", ref.parameter_a);
			break;
		case RPG::MoveCommand::Code::play_sound_effect:
			stream.WriteNode<std::string>("parameter_string", ref.parameter_string);
			stream.WriteNode<int>("parameter_a", ref.parameter_a);
			stream.WriteNode<int>("parameter_b", ref.parameter_b);
			stream.WriteNode<int>("parameter_c", ref.parameter_c);
			break;
	}
	stream.EndElement("MoveCommand");
}

class MoveCommandXmlHandler : public XmlHandler {
private:
	RPG::MoveCommand& ref;
	int* field;
	bool parameter_string;
public:
	MoveCommandXmlHandler(RPG::MoveCommand& ref) :
		ref(ref), field(NULL), parameter_string(false) {}
	void StartElement(XmlReader& stream, const char* name, const char** /* atts */) {
		if (strcmp(name, "command_id") == 0)
			field = &ref.command_id;
		else if (strcmp(name, "parameter_a") == 0)
			field = &ref.parameter_a;
		else if (strcmp(name, "parameter_b") == 0)
			field = &ref.parameter_b;
		else if (strcmp(name, "parameter_c") == 0)
			field = &ref.parameter_c;
		else if (strcmp(name, "parameter_string") == 0)
			parameter_string = true;
		else {
			stream.Error("Unrecognized field '%s'", name);
			field = NULL;
			parameter_string = false;
		}
	}
	void EndElement(XmlReader& /* stream */, const char* /* name */) {
		field = NULL;
		parameter_string = false;
	}
	void CharacterData(XmlReader& /* stream */, const std::string& data) {
		if (field != NULL)
			XmlReader::Read<int>(*field, data);
		else if (parameter_string)
			XmlReader::Read<std::string>(ref.parameter_string, data);
	}
};

void RawStruct<RPG::MoveCommand>::BeginXml(RPG::MoveCommand& ref, XmlReader& stream) {
	stream.SetHandler(new WrapperXmlHandler("MoveCommand", new MoveCommandXmlHandler(ref)));
}

/**
 * Reads Move Commands.
 */
void RawStruct<std::vector<RPG::MoveCommand> >::ReadLcf(std::vector<RPG::MoveCommand>& ref, LcfReader& stream, uint32_t length) {
	unsigned long startpos = stream.Tell();
	unsigned long endpos = startpos + length;
	do {
		RPG::MoveCommand command;
		RawStruct<RPG::MoveCommand>::ReadLcf(command, stream, 0);
		ref.push_back(command);
	} while (stream.Tell() != endpos);
}

void RawStruct<std::vector<RPG::MoveCommand> >::WriteLcf(const std::vector<RPG::MoveCommand>& ref, LcfWriter& stream) {
	std::vector<RPG::MoveCommand>::const_iterator it;
	for (it = ref.begin(); it != ref.end(); it++)
		RawStruct<RPG::MoveCommand>::WriteLcf(*it, stream);
}

int RawStruct<std::vector<RPG::MoveCommand> >::LcfSize(const std::vector<RPG::MoveCommand>& ref, LcfWriter& stream) {
	int result = 0;
	std::vector<RPG::MoveCommand>::const_iterator it;
	for (it = ref.begin(); it != ref.end(); it++)
		result += RawStruct<RPG::MoveCommand>::LcfSize(*it, stream);
	return result;
}

void RawStruct<std::vector<RPG::MoveCommand> >::WriteXml(const std::vector<RPG::MoveCommand>& ref, XmlWriter& stream) {
	std::vector<RPG::MoveCommand>::const_iterator it;
	for (it = ref.begin(); it != ref.end(); it++)
		RawStruct<RPG::MoveCommand>::WriteXml(*it, stream);
}

class MoveCommandVectorXmlHandler : public XmlHandler {
public:
	MoveCommandVectorXmlHandler(std::vector<RPG::MoveCommand>& ref) : ref(ref) {}

	void StartElement(XmlReader& stream, const char* name, const char** /* atts */) {
		if (strcmp(name, "MoveCommand") != 0)
			stream.Error("Expecting %s but got %s", "MoveCommand", name);
		ref.resize(ref.size() + 1);
		RPG::MoveCommand& obj = ref.back();
		stream.SetHandler(new MoveCommandXmlHandler(obj));
	}
private:
	std::vector<RPG::MoveCommand>& ref;
};

void RawStruct<std::vector<RPG::MoveCommand> >::BeginXml(std::vector<RPG::MoveCommand>& obj, XmlReader& stream) {
	stream.SetHandler(new MoveCommandVectorXmlHandler(obj));
}
