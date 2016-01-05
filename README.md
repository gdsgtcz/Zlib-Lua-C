# Zlib-Lua-C++

**用于在lua和C++中压缩字符串，可分开使用**

###1. lua-zlib目录下的lua_zlib.h文件用于压缩lua字符串，属于库文件。

* 使用
  
  我使用的开发环境是cocos2d-x + lua开发,以我的项目为例，
  将lua_zlib.h文件加入项目中，在入口文件中包含该头文件并注册以便在lua中使用，注册如下：
  
  ```
  luaL_requiref_(L, "zlib", luaopen_zlib, 1);
  ```
  
  然后lua中就可以使用如下：
  
  ```
  local zip=require("zlib")     
  local v,mv,pv=zip.version()
  print(v .. "  " .. mv .. "  " .. pv)
  local compress=zip.deflate()
  local uncompress=zip.inflate()
  
  -- 压缩字符串
  local deflated, eof, bytes_in,bytes_out =compress("asdasdasdasdasdasdasdasdasd", 'finish')
  print(deflated)
  print(eof)
  print(bytes_in)
  print(bytes_out)
  
  -- 解压字符串
  local uss,ret,getin,getout=uncompress(deflated)    
  print(uss)
  print(ret)
  print(getin)
  print(getout)
  ```
  
  'finish'为压缩选项，有 "none", "sync", "full", "finish", NULL，几种类型。
  
  
###2. C++使用zlib库封装后压缩字符串

主要是使用zlib库，封装后更容易使用。

* 使用

  将ZLibString.h,ZLibString.cpp文件加入项目，使用以下方法进行压缩，解压缩。

	```
// 压缩，pcContentBuf:要压缩的内容 pcCompBuf:压缩后的内容 ulCompLen:得到压缩后的长度
bool Compress(const char* pcContentBuf, char* pcCompBuf, unsigned long& ulCompLen);  
// 解压,pcCompBuf:压缩的内容, pcUnCompBuf:解压后的内容  ulCompLen:传入压缩内容的长度
bool UnCompress(const char* pcCompBuf, char* pcUnCompBuf, unsigned long ulCompLen); 
	```

具体见源码。