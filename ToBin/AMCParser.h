/*
-----------------------------------------------------------------------------
Filename:  AMCParser.h
-----------------------------------------------------------------------------
File Description: the file is used to parse motion capture data files with .amc format
-----------------------------------------------------------------------------
Author: Ancel         2011/12/1               alwssimple@gmail.com
-----------------------------------------------------------------------------
*/

#ifndef __AMCPARSER_H
#define __AMCPARSER_H

#include <vector>
#include <string>
struct DOF		//use to describe bone's degree of freedom
{
	bool mTx;
	bool mTy;
	bool mTz;
	bool mRx;
	bool mRy;
	bool mRz;
	int mNumFreedom;
	DOF( bool Rx, bool Ry, bool Rz,int NumFreedom,bool Tx = false, bool Ty = false, bool Tz = false)
		:mTx(Tx),mTy(Ty),mTz(Tz),mRx(Rx),mRy(Ry),mRz(Rz),mNumFreedom(NumFreedom)
	{}
};

class AMCParser
{
public:
	AMCParser();
	AMCParser(std::vector<DOF> BoneDOF);
	~AMCParser();
	bool loadMocapData(std::string filePath);
	void writeToFile(std::string  filePath);
private:
 	class DOFInitializer
	{
	public:
		static std::vector<DOF> Init();
	};
  	static const std::vector<DOF> mDefaultBoneDOF;
 	std::vector<std::vector<double>> mRawData;

	size_t mTotalDOF;
	std::vector<DOF> mBoneDOF;
};
 
#endif
