﻿#pragma once

#include <Uis/UiObject.hpp>
#include <Maths/Timer.hpp>
#include <Fonts/Text.hpp>

using namespace acid;

namespace test
{
	class OverlayDebug :
		public UiObject
	{
	public:
		explicit OverlayDebug(UiObject *parent);

		virtual void UpdateObject() override;
	private:
		std::unique_ptr<Text> CreateStatus(const std::string &content, const float &positionX, const float &positionY, const Text::Justify &justify);

		std::unique_ptr<Text> m_textFps;
		std::unique_ptr<Text> m_textUps;
		std::unique_ptr<Text> m_textPosition;
		std::unique_ptr<Text> m_textTime;
		Timer m_timerUpdate;

		float m_accumulatedFps;
		float m_accumulatedUps;
		uint32_t m_ticksPassed;
	};
}
