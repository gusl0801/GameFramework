#pragma once

/*
작성자 : 임종현
작성일 : 2018-03-09
설명   : CGameApp클래스의 윈도우 초기화 및 생성, 작업 처리
함수들을 순서에 맞게 호출할 수 있도록 제어하는 클래스입니다.
*/

// h파일에서 해당 매크로를 호출하여 디폴트 생성자를 선언하고 
// 싱글톤 클래스와 프랜드 선언을 하도록 합니다.
#define SINGLETON_DECL(T) protected: T(); friend class Singleton<T>; private:

// cpp파일에서 해당 매크로를 호출하여 싱글톤 인스턴스를 초기화 하도록 합니다.
#define SINGLETON_IMPL(T) T* Singleton<T>::instance = nullptr;

template <class T>
class Singleton
{
public:
	static void Create() { instance = new T; }
	static T* Get() { return instance; }
	static void Destroy() { delete instance; instance = nullptr; }

protected:
	static T* instance;
};

