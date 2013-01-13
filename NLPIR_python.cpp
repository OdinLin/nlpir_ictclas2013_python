#include <boost/python/module.hpp>
#include <boost/python.hpp>
#include "NLPIR.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Windows
#ifndef OS_LINUX
#pragma comment(lib, "lib/NLPIR.lib") //may modify
#endif

//Linux
#ifdef OS_LINUX
	#define _stricmp(X,Y) strcasecmp((X),(Y))
	#define _strnicmp(X,Y,Z) strncasecmp((X),(Y),(Z))
	#define strnicmp(X,Y,Z)	strncasecmp((X),(Y),(Z))
	#define _fstat(X,Y)     fstat((X),(Y))
	#define _fileno(X)     fileno((X))
	#define _stat           stat
	#define _getcwd         getcwd
	#define _off_t          off_t
	#define PATH_DELEMETER  "/"
#else
	#pragma warning(disable:4786)
	#define PATH_DELEMETER  "\\"
#endif


bool nlpir_init(const char* pDirPath)
{
    return NLPIR_Init(pDirPath);
}

bool nlpir_exit()
{
    return NLPIR_Exit();
}

unsigned int import_dict(const char *sFilename)
{
    return NLPIR_ImportUserDict(sFilename);
}

const char *process_str(const char *sParag, int bTagged)
{
    return NLPIR_ParagraphProcess(sParag, bTagged);
}

double process_file(const char *sSrcFilename,const char *sRetFilename,int bTagged)
{
    return NLPIR_FileProcess(sSrcFilename, sRetFilename, bTagged);
}

int add_user_word(const char *sWord)
{
	return NLPIR_AddUserWord(sWord);
}

int del_user_word(const char *sWord)
{
	return NLPIR_DelUsrWord(sWord);
}

int save_user_dic()
{
	return NLPIR_SaveTheUsrDic();
}

const char *get_keywords(const char *sLine,int nMaxKeyLimit=50,bool bWeightOut=false)
{
    return NLPIR_GetKeyWords(sLine, nMaxKeyLimit, bWeightOut);
}

const char *get_file_keywords(const char* pDirPath, int nMaxKeyLimit=50,bool bWeightOut=false)
{
    return NLPIR_GetFileKeyWords(pDirPath, nMaxKeyLimit, bWeightOut);
}

const char *get_new_words (const char *sLine,int nMaxKeyLimit=50,bool bWeightOut=false)
{
    return NLPIR_GetNewWords(sLine, nMaxKeyLimit, bWeightOut);
}

const char *get_file_new_words(const char *sTextFile,int nMaxKeyLimit=50,bool bWeightOut=false)
{
    return NLPIR_GetFileNewWords(sTextFile, nMaxKeyLimit, bWeightOut);
}

unsigned long get_fingerprint(const char *sLine)
{
	return NLPIR_FingerPrint(sLine);
}

//ICT_POS_MAP_FIRST		计算所一级标注集
//ICT_POS_MAP_SECOND	计算所二级标注集
//PKU_POS_MAP_SECOND	北大二级标注集						                 
//PKU_POS_MAP_FIRST 	北大一级标注集
int set_pos_map(int nPOSmap)	
{
	return NLPIR_SetPOSmap(nPOSmap);
}

bool NWI_start()
{
	return NLPIR_NWI_Start();
}

bool NWI_add_file(const char *sFilename)
{
	return NLPIR_NWI_AddFile(sFilename);
}

bool NWI_add_men(const char *sText)
{
	return NLPIR_NWI_AddMem(sText);
}

bool NWI_complete()
{
	return NLPIR_NWI_Complete();
}

const char *NWI_get_ret(bool bWeightOut=false)
{
	return NLPIR_NWI_GetResult(bWeightOut);
}

unsigned int NWI_result2user_dict()
{
	return NLPIR_NWI_Result2UserDict();
}

BOOST_PYTHON_MODULE(NLPIR)
{
	using namespace boost::python;

    def("nlpir_init", nlpir_init);
    def("nlpir_exit", nlpir_exit);
    def("import_dict", import_dict);
    def("process_str", process_str);
	def("process_file", process_file);
    def("add_user_word", add_user_word);
    def("del_user_word", del_user_word);
    def("save_user_dic", save_user_dic);
    def("get_keywords", get_keywords);
    def("get_file_keywords", get_file_keywords);
    def("get_new_words", get_new_words);
    def("get_file_new_words", get_file_new_words);
    def("get_fingerprint", get_fingerprint);	
    def("set_pos_map", set_pos_map);
    def("NWI_start", NWI_start);
    def("NWI_add_file", NWI_add_file);
    def("NWI_add_men", NWI_add_men);
    def("NWI_complete", NWI_complete);		
	def("NWI_get_ret", NWI_get_ret);	
	def("NWI_result2user_dict", NWI_result2user_dict);	
}
