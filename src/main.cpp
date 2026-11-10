#include <Windows.h>
#include <reshade.hpp>

namespace
{
    constexpr int kToggleKey = VK_F8;

    bool g_low_fps_mode = false;
    bool g_previous_effects_state = true;
    bool g_toggle_key_was_down = false;

    void set_low_fps_mode(
        reshade::api::effect_runtime runtime,
        bool enabled)
    {
        if (runtime == nullptr || enabled == g_low_fps_mode)
            return;

        if (enabled)
        {
            g_previous_effects_state = runtime->get_effects_state();
            runtime->set_effects_state(false);
        }
        else
        {
            runtime->set_effects_state(g_previous_effects_state);
        }

        g_low_fps_mode = enabled;
    }

    void on_reshade_present(reshade::api::effect_runtimeruntime)
    {
        if (runtime == nullptr)
            return;

        const bool key_down =
            (GetAsyncKeyState(kToggleKey) & 0x8000) != 0;

        if (key_down && !g_toggle_key_was_down)
        {
            set_low_fps_mode(runtime, !g_low_fps_mode);
        }

        g_toggle_key_was_down = key_down;
    }
}

extern "C" declspec(dllexport)
bool AddonInit(HMODULE addon_module, HMODULE reshade_module)
{
    if (!reshade::register_addon(addon_module, reshade_module))
        return false;

    reshade::register_event<reshade::addon_event::reshade_present>(
        &on_reshade_present);

    return true;
}

extern "C" declspec(dllexport)
void AddonUninit(HMODULE addon_module, HMODULE reshade_module)
{
    reshade::unregister_addon(addon_module, reshade_module);
}
