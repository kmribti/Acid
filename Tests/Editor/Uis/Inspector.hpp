#pragma once

#include <Uis/Inputs/UiInputButton.hpp>
#include <Uis/Inputs/UiInputGrabber.hpp>
#include <Uis/Inputs/UiInputSlider.hpp>
#include <Uis/Inputs/UiInputRadio.hpp>
#include <Uis/Inputs/UiInputText.hpp>
#include <Uis/Inputs/UiColourWheel.hpp>
#include <Uis/UiSection.hpp>
#include <Uis/UiPanel.hpp>
#include <Guis/Gui.hpp>

using namespace acid;

namespace test
{
	class Inspector :
		public UiPanel
	{
	public:
		explicit Inspector(UiObject *parent);

		void UpdateObject() override;
	private:
		std::unique_ptr<UiSection> m_section1;
		std::unique_ptr<UiInputButton> m_button1;
		std::unique_ptr<UiGrabberMouse> m_input1;
		std::unique_ptr<UiGrabberKeyboard> m_input2;
		std::unique_ptr<UiGrabberJoystick> m_input3;
		std::unique_ptr<UiInputSlider> m_slider1;
		std::unique_ptr<UiInputText> m_text1;
		std::unique_ptr<UiInputRadio> m_radio1;
		std::unique_ptr<UiInputRadio> m_radio2;
		std::unique_ptr<UiInputRadio> m_radio3;
		UiRadioManager m_radioManager;
	};
}
