#pragma once

#include "Matter/Core/Window.h"

#include <GLFW/glfw3.h>

namespace Matter {

	class WindowsWindow : public Window {

	public:
		WindowsWindow(const WindowProperties& properties);
		virtual ~WindowsWindow();

		void Update() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Initialize(const WindowProperties& properties);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;

		struct WindowData {

			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;

		};

		WindowData m_Data;

	};

}