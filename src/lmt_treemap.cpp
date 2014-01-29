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
#include "lmt_reader.h"
#include "lmt_chunks.h"
#include "reader_struct.h"

template <>
struct RawStruct<RPG::TreeMap> {
	static void ReadLcf(RPG::TreeMap& ref, LcfReader& stream, uint32_t length);
	static void WriteLcf(const RPG::TreeMap& ref, LcfWriter& stream);
	static int LcfSize(const RPG::TreeMap& ref, LcfWriter& stream);
	static void WriteXml(const RPG::TreeMap& ref, XmlWriter& stream);
	static void BeginXml(RPG::TreeMap& ref, XmlReader& stream);
};

/**
 * Reads Map Tree.
 */
void RawStruct<RPG::TreeMap>::ReadLcf(RPG::TreeMap& ref, LcfReader& stream, uint32_t /* length */) {
	Struct<RPG::MapInfo>::ReadLcf(ref.maps, stream);
	for (int i = stream.ReadInt(); i > 0; i--)
		ref.tree_order.push_back(stream.ReadInt());
	ref.active_node = stream.ReadInt();
	Struct<RPG::Start>::ReadLcf(ref.start, stream);
}

void RawStruct<RPG::TreeMap>::WriteLcf(const RPG::TreeMap& ref, LcfWriter& stream) {
	Struct<RPG::MapInfo>::WriteLcf(ref.maps, stream);
	int count = ref.tree_order.size();
	stream.WriteInt(count);
	for (int i = 0; i < count; i++)
		stream.WriteInt(ref.tree_order[i]);
	stream.WriteInt(ref.active_node);
	Struct<RPG::Start>::WriteLcf(ref.start, stream);
}

int RawStruct<RPG::TreeMap>::LcfSize(const RPG::TreeMap& /* ref */, LcfWriter& /* stream */) {
	/* doesn't matter; this structure never occurs within a chunk */
	return 0;
}

void RawStruct<RPG::TreeMap>::WriteXml(const RPG::TreeMap& ref, XmlWriter& stream) {
	stream.BeginElement("TreeMap");

	stream.BeginElement("maps");
	Struct<RPG::MapInfo>::WriteXml(ref.maps, stream);
	stream.EndElement("maps");

	stream.BeginElement("tree_order");
	stream.Write<std::vector<int> >(ref.tree_order);
	stream.EndElement("tree_order");

	stream.WriteNode<int>("active_node", ref.active_node);

	stream.BeginElement("start");
	Struct<RPG::Start>::WriteXml(ref.start, stream);
	stream.EndElement("start");

	stream.EndElement("TreeMap");
}

class TreeMapXmlHandler : public XmlHandler {
private:
	RPG::TreeMap& ref;
	bool active_node;
	bool tree_order;
public:
	TreeMapXmlHandler(RPG::TreeMap& ref) :
		ref(ref), active_node(false), tree_order(false) {}

	void StartElement(XmlReader& stream, const char* name, const char** /* atts */) {
		active_node = false;
		tree_order = false;
		if (strcmp(name, "maps") == 0)
			Struct<RPG::MapInfo>::BeginXml(ref.maps, stream);
		else if (strcmp(name, "tree_order") == 0)
			tree_order = true;
		else if (strcmp(name, "active_node") == 0)
			active_node = true;
		else if (strcmp(name, "start") == 0)
			Struct<RPG::Start>::BeginXml(ref.start, stream);
		else {
			stream.Error("Unrecognized field '%s'", name);
		}
	}
	void EndElement(XmlReader& /* stream */, const char* /* name */) {
		active_node = false;
		tree_order = false;
	}
	void CharacterData(XmlReader& /* stream */, const std::string& data) {
		if (active_node)
			XmlReader::Read<int>(ref.active_node, data);
		if (tree_order)
			XmlReader::Read<std::vector<int> >(ref.tree_order, data);
	}
};

void RawStruct<RPG::TreeMap>::BeginXml(RPG::TreeMap& ref, XmlReader& stream) {
	stream.SetHandler(new WrapperXmlHandler("TreeMap", new TreeMapXmlHandler(ref)));
}
