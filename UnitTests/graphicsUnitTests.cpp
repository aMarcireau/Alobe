#include "stdafx.h"
#include "CppUnitTest.h"

#include <memory>

#include "graphics.cpp"
#include "graphicsWindow.h"
#include "graphicsWindow.cpp"
#include "sfmlGraphics.h"
#include "sfmlGraphics.cpp"
#include "sfmlGraphicsWindow.h"
#include "sfmlGraphicsWindow.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(GraphicsUnitTests)
{
public:
	TEST_METHOD(GraphicsUnitTest) {
		shared_ptr<GraphicsWindow> sfmlGraphicsWindow = make_shared<SfmlGraphicsWindow>(800, 800);
		SfmlGraphics sfmlGraphics(sfmlGraphicsWindow);

		sfmlGraphics.setXOffset(100);
		sfmlGraphics.setYOffset(200);
		sfmlGraphics.setWidth(300);
		sfmlGraphics.setHeight(400);

		try {
			sfmlGraphics.drawStripes(0, 100, 0, 100, "horizontal", 10, 2);			
		} catch (...) {
			Assert::Fail(L"Error in drawStripes", LINE_INFO());
		}

		try {
			sfmlGraphics.drawRectangle(0, 100, 0, 100);
		} catch (...) {
			Assert::Fail(L"Error in drawRectangle", LINE_INFO());
		}
		
		try {
			sfmlGraphics.drawCircle(100, 100, 10);			
		} catch (...) {
			Assert::Fail(L"Error in drawCircle", LINE_INFO());
		}

		try {
			sfmlGraphics.drawText(100, 100, "output", 10);
		} catch (...) {
			Assert::Fail(L"Error in drawText", LINE_INFO());
		}

		Assert::AreEqual(
			(unsigned long)(100),
			sfmlGraphics.getXOffset(),
			L"Wrong x offset storing",
			LINE_INFO()
		);
		Assert::AreEqual(
			(unsigned long)(200),
			sfmlGraphics.getYOffset(),
			L"Wrong x offset storing",
			LINE_INFO()
		);
		Assert::AreEqual(
			(unsigned long)(300),
			sfmlGraphics.getWidth(),
			L"Wrong x offset storing",
			LINE_INFO()
		);
		Assert::AreEqual(
			(unsigned long)(400),
			sfmlGraphics.getHeight(),
			L"Wrong x offset storing",
			LINE_INFO()
		);
	}
};
