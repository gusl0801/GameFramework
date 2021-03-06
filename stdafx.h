// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// 정의
#define CLIENT_WIDTH   480
#define CLIENT_HEIGHT  640

#define UPDATE_FPS 1.0f / 60.0f

#define SAFE_DELETE(T) if(T) delete T; T = nullptr;
//
// 디버그 모드인 경우, 텍스트 형식에 맞게 윈도우 하위 창으로 콘솔을 사용
#ifdef _DEBUG		
	#ifdef UNICODE
		#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
	#else
		#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
	#endif
#endif	

// 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <atlimage.h>
#include <chrono>
using namespace std;