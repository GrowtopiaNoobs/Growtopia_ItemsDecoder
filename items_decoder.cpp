/*
	Decoder of file items.dat which can be found in Growtopia
	Copyright (c) 2019 Growtopia Noobs
*/

#include <fstream>
#include <string>
#include <iostream>
#ifndef __linux__
#include <conio.h>
#endif
#include "json.hpp"
#include <iomanip>
using namespace std;

string secret = "PBG892FXX982ABC*";

using json = nlohmann::json;

int main()
{
	std::ifstream file("items.dat", std::ios::binary | std::ios::ate);
	int size = file.tellg();
	if(size == -1) {
		cout << "Failed to open file, are you sure that you have items.dat in current directory?" << std::endl;
		return 0;
	}
	char* data = new char[size];
	file.seekg(0, std::ios::beg);

	if (file.read((char*)(data), size))
	{
		cout << "Decoding items data..." << endl;

	}
	else {
		cout << "Decoding of items data has failed..." << endl;
#ifndef __linux__
	_getch();
#endif
		exit(0);
	}
	int itemCount;
	int memPos = 0;
	int16_t itemsdatVersion = 0;
	memcpy(&itemsdatVersion, data + memPos, 2);
	memPos += 2;
	memcpy(&itemCount, data + memPos, 4);
	memPos += 4;
	cout << "Itemcount: " << itemCount << "\nitemsdatVersion: " << itemsdatVersion << endl;
	for (int i=0;i<itemCount;i++) {
		json j;
		int itemID = 0;
		char editableType = 0;
		char itemCategory = 0;
		char actionType = 0;
		char hitSoundType = 0;
		string name = "";
		string texture = "";
		int textureHash = 0;
		char itemKind = 0;
		int val1;
		char textureX = 0;
		char textureY = 0;
		char spreadType = 0;
		char isStripeyWallpaper = 0;
		char collisionType = 0;
		char breakHits = 0;
		int dropChance = 0;
		char clothingType = 0;
		int16_t rarity = 0;
		unsigned char maxAmount = 0;
		string extraFile = "";
		int extraFileHash = 0;
		int audioVolume = 0;
		string petName = "";
		string petPrefix = "";
		string petSuffix = "";
		string petAbility = "";
		char seedBase = 0;
		char seedOverlay = 0;
		char treeBase = 0;
		char treeLeaves = 0;
		int seedColor = 0;
		int seedOverlayColor = 0;
		int growTime = 0;
		short val2;
		short isRayman = 0;
		string extraOptions = "";
		string texture2 = "";
		string extraOptions2 = "";
		string punchOptions = "";
		{
			memcpy(&itemID, data + memPos, 4);
			memPos += 4;
		}
		{
			editableType = data[memPos];
			memPos += 1;
		}
		{
			itemCategory = data[memPos];
			memPos += 1;
		}
		{
			actionType = data[memPos];
			memPos += 1;
		}
		{
			hitSoundType = data[memPos];
			memPos += 1;
		}
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				name += data[memPos] ^ (secret[(j + itemID) % secret.length()]);
				memPos++;
			}
		}
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				texture += data[memPos];
				memPos++;
			}
		}
		memcpy(&textureHash, data + memPos, 4);
		memPos += 4;
		itemKind = memPos[data];
		memPos += 1;
		memcpy(&val1, data + memPos, 4);
		memPos += 4;
		textureX = data[memPos];
		memPos += 1;
		textureY = data[memPos];
		memPos += 1;
		spreadType = data[memPos];
		memPos += 1;
		isStripeyWallpaper = data[memPos];
		memPos += 1;
		collisionType = data[memPos];
		memPos += 1;
		breakHits = data[memPos];
		memPos += 1;
		memcpy(&dropChance, data + memPos, 4);
		memPos += 4;
		clothingType = data[memPos];
		memPos += 1;
		memcpy(&rarity, data + memPos, 2);
		memPos += 2;
		maxAmount = data[memPos];
		memPos += 1;
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				extraFile += data[memPos];
				memPos++;
			}
		}
		memcpy(&extraFileHash, data + memPos, 4);
		memPos += 4;
		memcpy(&audioVolume, data + memPos, 4);
		memPos += 4;
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				petName += data[memPos];
				memPos++;
			}
		}
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				petPrefix += data[memPos];
				memPos++;
			}
		}
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				petSuffix += data[memPos];
				memPos++;
			}
		}
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				petAbility += data[memPos];
				memPos++;
			}
		}
		{
			seedBase = data[memPos];
			memPos += 1;
		}
		{
			seedOverlay = data[memPos];
			memPos += 1;
		}
		{
			treeBase = data[memPos];
			memPos += 1;
		}
		{
			treeLeaves = data[memPos];
			memPos += 1;
		}
		{
			memcpy(&seedColor, data + memPos, 4);
			memPos += 4;
		}
		{
			memcpy(&seedOverlayColor, data + memPos, 4);
			memPos += 4;
		}
		memPos += 4; // deleted ingredients
		{
			memcpy(&growTime, data + memPos, 4);
			memPos += 4;
		}
		memcpy(&val2, data + memPos, 2);
		memPos += 2;
		memcpy(&isRayman, data + memPos, 2);
		memPos += 2;
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				extraOptions += data[memPos];
				memPos++;
			}
		}
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				texture2 += data[memPos];
				memPos++;
			}
		}
		{
			int16_t strLen = *(int16_t*)&data[memPos];
			memPos += 2;
			for (int j = 0; j < strLen; j++) {
				extraOptions2 += data[memPos];
				memPos++;
			}
		}
		memPos += 80;
		if(itemsdatVersion >= 11) {
			{
				int16_t strLen = *(int16_t*)&data[memPos];
				memPos += 2;
				for (int j = 0; j < strLen; j++) {
					punchOptions += data[memPos];
					memPos++;
				}
			}
		}
		if(itemsdatVersion >= 12) {
			// TODO: find what those data mean
			memPos += 13;
		}
                If (itemsdatVersion >= 13) {
                      memPos += 4;
                }
		if (i != itemID)
			cout << "Item are unordered!" << endl;
		j["itemID"] = itemID;
		j["hitSoundType"] = hitSoundType;
		j["name"] = name;
		j["texture"] = texture;
		j["textureHash"] = textureHash;
		j["val1"] = val1;
		j["itemKind"] = itemKind;
		j["editableType"] = editableType;
		j["itemCategory"] = itemCategory;
		j["actionType"] = actionType;
		j["textureX"] = textureX;
		j["textureY"] = textureY;
		j["spreadType"] = spreadType;
		j["isStripeyWallpaper"] = isStripeyWallpaper;
		j["collisionType"] = collisionType;
		j["breakHits"] = breakHits;
		j["dropChance"] = dropChance;
		j["clothingType"] = clothingType;
		j["rarity"] = rarity;
		j["maxAmount"] = maxAmount;
		j["extraFile"] = extraFile;
		j["extraFileHash"] = extraFileHash;
		j["audioVolume"] = audioVolume;
		j["petName"] = petName;
		j["petPrefix"] = petPrefix;
		j["petSuffix"] = petSuffix;
		j["petAbility"] = petAbility;
		j["seedColor"] = seedColor;
		j["seedBase"] = seedBase;
		j["seedOverlay"] = seedOverlay;
		j["treeBase"] = treeBase;
		j["treeLeaves"] = treeLeaves;
		j["seedOverlayColor"] = seedOverlayColor;
		j["growTime"] = growTime;
		j["val2"] = val2;
		j["isRayman"] = isRayman;
		j["extraOptions"] = extraOptions;
		j["texture2"] = texture2;
		j["extraOptions2"] = extraOptions2;
		j["punchOptions"] = punchOptions;
		jdata["items"].push_back(j);
		ofstream items;
		items.open("items/" + to_string(itemID) + ".json");
		items << j << endl;
		items.close();
	}
	cout << "Succesfully decoded" << endl;
#ifndef __linux__
	_getch();
#endif
	string answ;
	cout << "Do you want to delete all items from folder? (Y/N) : ";
	getline(cin, answ);
	if (answ == "Y")
	{
		for (int i = 0; i < itemCount; i++)
		remove(("items/" + to_string(i) + ".json").c_str());
	}
	else {
		return 0;
	}
}


