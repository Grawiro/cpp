#pragma once

#ifndef DLL_H
#define DLL_H

#if defined DLL_EXPORT
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif // 

extern "C"
{
	EXPORT int Sum (int, int);
}
#endif // !DLL_H