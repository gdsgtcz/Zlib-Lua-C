//
//  ZLibString.cpp
//  hhl
//
//  Created by guodi on 15/10/26.
//
//

#include "ZLibString.h"

CZlibMgr* CZlibMgr::instance = NULL;

CZlibMgr::CZlibMgr()
{
}

CZlibMgr::~CZlibMgr()
{
}

CZlibMgr* CZlibMgr::getInstance()
{
    if (instance == NULL) {
        instance = new CZlibMgr();
    }
    return instance;
}

bool CZlibMgr::Compress(const char* pcContentBuf, char* pcCompBuf, unsigned long& ulCompLen)
{
    if (pcContentBuf == NULL)
    {
        return false;
    }
    
    if (strlen(pcContentBuf) == 0)
    {
        return false;
    }
    
    memset(compr, 0, MAXBUFFERSIZE);
    
    uLong comprLen;
    int err;
    
    uLong len = strlen(pcContentBuf);
    comprLen = sizeof(compr) / sizeof(compr[0]);
    
    err = compress(compr, &comprLen, (const Bytef*)pcContentBuf, len);
    if (err != Z_OK)
    {
        cout << "compess error: " << err << endl;
        return false;
    }
    cout << "orignal size: " << len << " , compressed size : " << comprLen << endl;
    memcpy(pcCompBuf, compr, comprLen);
    ulCompLen = comprLen;
    
    return true;
}

bool CZlibMgr::UnCompress(const char* pcCompBuf, char* pcUnCompBuf, unsigned long ulCompLen)
{
    if (pcCompBuf == NULL)
    {
        cout <<__FUNCTION__ << "================> pcCompBuf is null please to check " << endl;
        return false;
    }
    
    if (strlen(pcCompBuf) == 0)
    {
        cout <<__FUNCTION__ << "strlen(pcCompBuf) == 0  ========================> " << endl;
        return false;
    }
    
    memset(uncompr, 0, MAXBUFFERSIZE);
    uLong uncomprLen = MAXBUFFERSIZE;
    int err;
    
    err = uncompress(uncompr, &uncomprLen, (const Bytef *)pcCompBuf, ulCompLen);
    if (err != Z_OK)
    {
        cout << "uncompess error: " << err << endl;
        return false;
    }
    
    cout << "compress size: " << ulCompLen << "  uncompressed size : " << uncomprLen << endl;
    memcpy(pcUnCompBuf, uncompr, uncomprLen);
    
    return true;
}

