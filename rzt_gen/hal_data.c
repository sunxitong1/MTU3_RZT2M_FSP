/* generated HAL source file - do not edit */
#include "hal_data.h"

mtu3_instance_ctrl_t g_timer1_ctrl;
#if 0
const mtu3_extended_uvw_cfg_t g_timer1_uvw_extend =
{
    .tgru_val                       = 0x0000,
    .tgrv_val                       = 0x0000,
    .tgrw_val                       = 0x0000,
    .mtu3_clk_div_u                 = MTU3_DIV_UVW_PCLKH_1,
    .mtu3_clk_div_v                 = MTU3_DIV_UVW_PCLKH_1,
    .mtu3_clk_div_w                 = MTU3_DIV_UVW_PCLKH_1,
    .output_pin_level_u             = MTU3_IO_PIN_LEVEL_UVW_NO_FUNC,
    .output_pin_level_v             = MTU3_IO_PIN_LEVEL_UVW_NO_FUNC,
    .output_pin_level_w             = MTU3_IO_PIN_LEVEL_UVW_NO_FUNC,
    .noise_filter_mtioc_setting_uvw = (mtu3_noise_filter_setting_uvw_t)(MTU3_NOISE_FILTER_UVW_DISABLE),
    .noise_filter_mtioc_clk_uvw     = MTU3_NOISE_FILTER_CLOCK_PCLKH_DIV_1,

    .capture_u_ipl                  = (BSP_IRQ_DISABLED),
    .capture_v_ipl                  = (BSP_IRQ_DISABLED),
    .capture_w_ipl                  = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_MTU34_U)
    .capture_u_irq                  = VECTOR_NUMBER_MTU34_U,
#else
    .capture_u_irq                  = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_MTU34_V)
    .capture_v_irq                  = VECTOR_NUMBER_MTU34_V,
#else
    .capture_v_irq                  = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_MTU34_W)
    .capture_w_irq                  = VECTOR_NUMBER_MTU34_W,
#else
    .capture_w_irq                  = FSP_INVALID_VECTOR,
#endif
};
const mtu3_extended_pwm_cfg_t g_timer1_pwm_extend =
{
    .interrupt_skip_mode_a          = MTU3_INTERRUPT_SKIP_MODE_1,
    .interrupt_skip_mode_b          = MTU3_INTERRUPT_SKIP_MODE_1,
    .adc_a_compare_match            = 0x0000,
    .adc_b_compare_match            = 0x0000,
    .interrupt_skip_count_tciv4     = MTU3_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_count_tgia3     = MTU3_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_count_tciv7     = MTU3_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_count_tgia6     = MTU3_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_count_tgr4an_bn = MTU3_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_count_tgr7an_bn = MTU3_INTERRUPT_SKIP_COUNT_0,
};
#endif
const mtu3_extended_cfg_t g_timer1_extend = { .tgra_val = 0, .tgrb_val = 0,
		.tgrc_val = 0, .tgrd_val = 0, .mtu3_clk_div = MTU3_DIV_PCLKH_4,
		.clk_edge = MTU3_CLOCK_EDGE_RISING, .mtu3_clear =
				MTU3_TCNT_CLEAR_DISABLE, .mtioc_ctrl_setting = {
				.output_pin_level_a = MTU3_IO_PIN_LEVEL_NO_OUTPUT,
				.output_pin_level_b = MTU3_IO_PIN_LEVEL_NO_OUTPUT },
		.capture_a_ipl = (BSP_IRQ_DISABLED),
		.capture_b_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_MTU34_CCMPA)
    .capture_a_irq       = VECTOR_NUMBER_MTU34_CCMPA,
#else
		.capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_MTU34_CCMPB)
    .capture_b_irq       = VECTOR_NUMBER_MTU34_CCMPB,
#else
		.capture_b_irq = FSP_INVALID_VECTOR,
#endif
		.noise_filter_mtioc_setting = (mtu3_noise_filter_setting_t)(
				MTU3_NOISE_FILTER_DISABLE), .noise_filter_mtioc_clk =
				MTU3_NOISE_FILTER_CLOCK_PCLKH_DIV_1,
		.noise_filter_mtclk_setting = (mtu3_noise_filter_mtclk_setting_t)(
				MTU3_NOISE_FILTER_EXTERNAL_DISABLE), .noise_filter_mtclk_clk =
				MTU3_NOISE_FILTER_EXTERNAL_CLOCK_PCLKH_DIV_1,
#if 0
    .p_uvw_cfg                   = &g_timer1_uvw_extend,
    .p_pwm_cfg                   = &g_timer1_pwm_extend,
#else
		.p_uvw_cfg = NULL, .p_pwm_cfg = NULL,
#endif
		};
const timer_cfg_t g_timer1_cfg = { .mode = TIMER_MODE_PERIODIC, .channel = 4,
		.p_callback = my_fun, .p_context = NULL, .p_extend = &g_timer1_extend,
		.cycle_end_ipl = (11),
#if defined(VECTOR_NUMBER_MTU34_OVF)
    .cycle_end_irq       = VECTOR_NUMBER_MTU34_OVF,
#else
		.cycle_end_irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const timer_instance_t g_timer1 = { .p_ctrl = &g_timer1_ctrl, .p_cfg =
		&g_timer1_cfg, .p_api = &g_timer_on_mtu3 };
mtu3_instance_ctrl_t g_timer0_ctrl;
#if 0
const mtu3_extended_uvw_cfg_t g_timer0_uvw_extend =
{
    .tgru_val                       = 0x0000,
    .tgrv_val                       = 0x0000,
    .tgrw_val                       = 0x0000,
    .mtu3_clk_div_u                 = MTU3_DIV_UVW_PCLKH_1,
    .mtu3_clk_div_v                 = MTU3_DIV_UVW_PCLKH_1,
    .mtu3_clk_div_w                 = MTU3_DIV_UVW_PCLKH_1,
    .output_pin_level_u             = MTU3_IO_PIN_LEVEL_UVW_NO_FUNC,
    .output_pin_level_v             = MTU3_IO_PIN_LEVEL_UVW_NO_FUNC,
    .output_pin_level_w             = MTU3_IO_PIN_LEVEL_UVW_NO_FUNC,
    .noise_filter_mtioc_setting_uvw = (mtu3_noise_filter_setting_uvw_t)(MTU3_NOISE_FILTER_UVW_DISABLE),
    .noise_filter_mtioc_clk_uvw     = MTU3_NOISE_FILTER_CLOCK_PCLKH_DIV_1,

    .capture_u_ipl                  = (BSP_IRQ_DISABLED),
    .capture_v_ipl                  = (BSP_IRQ_DISABLED),
    .capture_w_ipl                  = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_MTU33_U)
    .capture_u_irq                  = VECTOR_NUMBER_MTU33_U,
#else
    .capture_u_irq                  = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_MTU33_V)
    .capture_v_irq                  = VECTOR_NUMBER_MTU33_V,
#else
    .capture_v_irq                  = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_MTU33_W)
    .capture_w_irq                  = VECTOR_NUMBER_MTU33_W,
#else
    .capture_w_irq                  = FSP_INVALID_VECTOR,
#endif
};
const mtu3_extended_pwm_cfg_t g_timer0_pwm_extend =
{
    .interrupt_skip_mode_a          = MTU3_INTERRUPT_SKIP_MODE_1,
    .interrupt_skip_mode_b          = MTU3_INTERRUPT_SKIP_MODE_1,
    .adc_a_compare_match            = 0x0000,
    .adc_b_compare_match            = 0x0000,
    .interrupt_skip_count_tciv4     = MTU3_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_count_tgia3     = MTU3_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_count_tciv7     = MTU3_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_count_tgia6     = MTU3_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_count_tgr4an_bn = MTU3_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_count_tgr7an_bn = MTU3_INTERRUPT_SKIP_COUNT_0,
};
#endif
const mtu3_extended_cfg_t g_timer0_extend = { .tgra_val = 0xa28, .tgrb_val = 0,
		.tgrc_val = 0xa28, .tgrd_val = 0, .mtu3_clk_div = MTU3_DIV_PCLKH_4,
		.clk_edge = MTU3_CLOCK_EDGE_RISING, .mtu3_clear =
				MTU3_TCNT_CLEAR_DISABLE, .mtioc_ctrl_setting = {
				.output_pin_level_a = MTU3_IO_PIN_LEVEL_NO_OUTPUT,
				.output_pin_level_b = MTU3_IO_PIN_LEVEL_NO_OUTPUT },
		.capture_a_ipl = (BSP_IRQ_DISABLED),
		.capture_b_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_MTU33_CCMPA)
    .capture_a_irq       = VECTOR_NUMBER_MTU33_CCMPA,
#else
		.capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_MTU33_CCMPB)
    .capture_b_irq       = VECTOR_NUMBER_MTU33_CCMPB,
#else
		.capture_b_irq = FSP_INVALID_VECTOR,
#endif
		.noise_filter_mtioc_setting = (mtu3_noise_filter_setting_t)(
				MTU3_NOISE_FILTER_DISABLE), .noise_filter_mtioc_clk =
				MTU3_NOISE_FILTER_CLOCK_PCLKH_DIV_1,
		.noise_filter_mtclk_setting = (mtu3_noise_filter_mtclk_setting_t)(
				MTU3_NOISE_FILTER_EXTERNAL_DISABLE), .noise_filter_mtclk_clk =
				MTU3_NOISE_FILTER_EXTERNAL_CLOCK_PCLKH_DIV_1,
#if 0
    .p_uvw_cfg                   = &g_timer0_uvw_extend,
    .p_pwm_cfg                   = &g_timer0_pwm_extend,
#else
		.p_uvw_cfg = NULL, .p_pwm_cfg = NULL,
#endif
		};
const timer_cfg_t g_timer0_cfg = { .mode = TIMER_MODE_PERIODIC, .channel = 3,
		.p_callback = NULL, .p_context = NULL, .p_extend = &g_timer0_extend,
		.cycle_end_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_MTU33_OVF)
    .cycle_end_irq       = VECTOR_NUMBER_MTU33_OVF,
#else
		.cycle_end_irq = FSP_INVALID_VECTOR,
#endif
		};
/* Instance structure to use this module. */
const timer_instance_t g_timer0 = { .p_ctrl = &g_timer0_ctrl, .p_cfg =
		&g_timer0_cfg, .p_api = &g_timer_on_mtu3 };
mtu3_three_phase_instance_ctrl_t g_three_phase0_ctrl;
const mtu3_three_phase_extended_cfg_t g_three_phase0_extend = { .pwm_mode =
		MTU3_THREE_PHASE_PWM_MODE_1, .period_half = 0x1388 / 2, .dead_time =
		0x64, .duty_val = { 0, 0, 0 }, .period_out =
		MTU3_THREE_PHASE_PSYE_TOGGLE, .level =
		MTU3_THREE_PHASE_OUTPUT_LEVEL_ACTIVE_HIGH, .duty_double = { 0, 0, 0 },
		.sync = MTU3_THREE_PHASE_SYNCHRONOUS_CHANNEL_DISABLE };
const three_phase_cfg_t g_three_phase0_cfg = { .buffer_mode =
		THREE_PHASE_BUFFER_MODE_SINGLE, .p_timer_instance = { &g_timer0,
		&g_timer1 }, .channel_mask = (1 << 3) | (1 << 4), .p_context = NULL,
		.p_extend = &g_three_phase0_extend, };
/* Instance structure to use this module. */
const three_phase_instance_t g_three_phase0 = { .p_ctrl = &g_three_phase0_ctrl,
		.p_cfg = &g_three_phase0_cfg, .p_api =
				&g_three_phase_on_mtu3_three_phase };
poe3_instance_ctrl_t g_poe30_ctrl;
/** POE3 setting. */
const poe3_cfg_t g_poe30_cfg = { .poe0 = { .mode = POE3_HIZ_MODE_FALLING_EDGE,
		.interrupt = POE3_INTERRUPT_ENABLE_DISABLED, .mtioc3b_mtioc3d = {
				.mtioc3b_pin_select = POE3_MTIOC3B_PIN_SELECT_P17_6,
				.mtioc3d_pin_select = POE3_MTIOC3D_PIN_SELECT_P18_1,
				.mtioc3b_active_level = POE3_ACTIVE_LEVEL_HIGH,
				.mtioc3d_active_level = POE3_ACTIVE_LEVEL_HIGH, .hiz_output =
						POE3_HIZ_OUTPUT_ENABLE_ENABLED }, .mtioc4b_mtioc4d = {
				.mtioc4b_pin_select = POE3_MTIOC4B_PIN_SELECT_P18_2,
				.mtioc4d_pin_select = POE3_MTIOC4D_PIN_SELECT_P18_3,
				.mtioc4b_active_level = POE3_ACTIVE_LEVEL_HIGH,
				.mtioc4d_active_level = POE3_ACTIVE_LEVEL_HIGH, .hiz_output =
						POE3_HIZ_OUTPUT_ENABLE_ENABLED }, .mtioc4a_mtioc4c = {
				.mtioc4a_pin_select = POE3_MTIOC4A_PIN_SELECT_P17_7,
				.mtioc4c_pin_select = POE3_MTIOC4C_PIN_SELECT_P18_0,
				.mtioc4a_active_level = POE3_ACTIVE_LEVEL_HIGH,
				.mtioc4c_active_level = POE3_ACTIVE_LEVEL_HIGH, .hiz_output =
						POE3_HIZ_OUTPUT_ENABLE_ENABLED } }, .poe4 = { .mode =
		POE3_HIZ_MODE_FALLING_EDGE, .interrupt = POE3_INTERRUPT_ENABLE_DISABLED,
		.mtioc6b_mtioc6d = {
				.mtioc6b_pin_select = POE3_MTIOC6B_PIN_SELECT_P19_3,
				.mtioc6d_pin_select = POE3_MTIOC6D_PIN_SELECT_P19_6,
				.hiz_output = POE3_HIZ_OUTPUT_ENABLE_DISABLED },
		.mtioc7b_mtioc7d = {
				.mtioc7b_pin_select = POE3_MTIOC7B_PIN_SELECT_P19_7,
				.mtioc7d_pin_select = POE3_MTIOC7D_PIN_SELECT_P20_0,
				.hiz_output = POE3_HIZ_OUTPUT_ENABLE_DISABLED },
		.mtioc7a_mtioc7c = {
				.mtioc7a_pin_select = POE3_MTIOC7A_PIN_SELECT_P19_4,
				.mtioc7c_pin_select = POE3_MTIOC7C_PIN_SELECT_P19_5,
				.hiz_output = POE3_HIZ_OUTPUT_ENABLE_DISABLED } }, .poe8 = {
		.mode = POE3_HIZ_MODE_FALLING_EDGE, .interrupt =
				POE3_INTERRUPT_ENABLE_DISABLED, .mtioc0a = { .pin_select =
				POE3_MTIOC0A_PIN_SELECT_P13_2, .hiz_output =
				POE3_HIZ_OUTPUT_ENABLE_DISABLED }, .mtioc0b = { .pin_select =
				POE3_MTIOC0B_PIN_SELECT_P11_5, .hiz_output =
				POE3_HIZ_OUTPUT_ENABLE_DISABLED }, .mtioc0c = { .pin_select =
				POE3_MTIOC0C_PIN_SELECT_P13_3, .hiz_output =
				POE3_HIZ_OUTPUT_ENABLE_DISABLED }, .mtioc0d = { .pin_select =
				POE3_MTIOC0D_PIN_SELECT_P13_4, .hiz_output =
				POE3_HIZ_OUTPUT_ENABLE_DISABLED } }, .oscillation_stop =
		POE3_HIZ_OUTPUT_ENABLE_DISABLED, .dsmif0_error =
		POE3_HIZ_OUTPUT_ENABLE_DISABLED, .dsmif1_error =
		POE3_HIZ_OUTPUT_ENABLE_DISABLED, .short_circuit1 = { .interrupt =
		POE3_INTERRUPT_ENABLE_DISABLED, .hiz_output =
		POE3_HIZ_OUTPUT_ENABLE_DISABLED }, .short_circuit2 = { .interrupt =
		POE3_INTERRUPT_ENABLE_DISABLED, .hiz_output =
		POE3_HIZ_OUTPUT_ENABLE_DISABLED }, .p_context = NULL, };
/* Instance structure to use this module. */
const poe3_instance_t g_poe30 = { .p_ctrl = &g_poe30_ctrl,
		.p_cfg = &g_poe30_cfg, .p_api = &g_poe30_on_poe3 };
void g_hal_init(void) {
	g_common_init();
}
