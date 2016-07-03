// ======================================================================
// InterIcSound01.v generated from TopDesign.cysch
// 06/26/2016 at 16:55
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_TMA4 2
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 3
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PANTHER 5
`define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1
`define CYDEV_CHIP_REV_PANTHER_ES1 1
`define CYDEV_CHIP_REV_PANTHER_ES0 0
`define CYDEV_CHIP_DIE_EXPECT 4
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 4
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_MEMBER_4G 2
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 3
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 4
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 5
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 6
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 7
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 8
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 9
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 10
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 11
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 12
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4F 13
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4M 14
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 15
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 16
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4C 17
`define CYDEV_CHIP_REVISION_4C_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_MEMBER_5B 18
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 19
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 18
`define CYDEV_CHIP_REVISION_USED 0
// Component: bI2S_v2_70
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bI2S_v2_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bI2S_v2_70\bI2S_v2_70.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bI2S_v2_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bI2S_v2_70\bI2S_v2_70.v"
`endif

// I2S_v2_70(ClipPresent=false, ClockSyncMode=true, CommonClipThresholds=false, DataBits=16, Direction=2, EnableClipDetect=false, EnableRxByteSwap=false, EnableTxByteSwap=false, InterruptSource=0, NegThresholds=-64, -64, -64, -64, -64, NumRxChannels=2, NumRxLines=1, NumTxChannels=2, NumTxLines=1, PosThresholds=64u, 64u, 64u, 64u, 64u, RxDataInterleaved=true, RxDataInterleaving=1, RxDMA_present=1, RxDmaPresent=false, RxInterruptSource=0, RxStsReg0Present=false, RxStsReg1Present=false, RxStsReg2Present=false, StaticBitResolution=true, TermVisibility_clip=false, TermVisibility_clock=true, TermVisibility_rx_dma0=false, TermVisibility_rx_dma1=false, TermVisibility_rx_interrupt=false, TermVisibility_sck=true, TermVisibility_sdi=false, TermVisibility_sdo=true, TermVisibility_tx_dma0=true, TermVisibility_tx_dma1=false, TermVisibility_tx_interrupt=true, TermVisibility_ws=true, TxDataInterleaved=true, TxDataInterleaving=1, TxDMA_present=1, TxDmaPresent=true, TxInterruptSource=0, TxStsReg0Present=true, TxStsReg1Present=false, TxStsReg2Present=false, WordSelect=64, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=I2S_v2_70, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=I2S_1, CY_INSTANCE_SHORT_NAME=I2S_1, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=70, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 SP2, INSTANCE_NAME=I2S_1, )
module I2S_v2_70_0 (
    clock,
    sdi,
    sck,
    ws,
    sdo,
    tx_interrupt,
    rx_dma0,
    rx_dma1,
    tx_dma0,
    tx_dma1,
    rx_interrupt,
    clip);
    input       clock;
    input      [4:0] sdi;
    output      sck;
    output      ws;
    output     [4:0] sdo;
    output      tx_interrupt;
    output     [4:0] rx_dma0;
    output     [4:0] rx_dma1;
    output     [4:0] tx_dma0;
    output     [4:0] tx_dma1;
    output      rx_interrupt;
    output     [4:0] clip;


          wire [4:0] tx_line;
          wire [4:0] tx_drq1;
          wire [4:0] rx_drq1;
          wire [4:0] tx_drq0;
          wire [4:0] rx_drq0;
          wire [4:0] rx_line;
          wire [4:0] clip_detect;

    bI2S_v2_70 bI2S (
        .sdi(rx_line[4:0]),
        .clock(clock),
        .sdo(tx_line[4:0]),
        .sck(sck),
        .ws(ws),
        .rx_interrupt(rx_interrupt),
        .tx_interrupt(tx_interrupt),
        .rx_dma0(rx_drq0[4:0]),
        .tx_dma0(tx_drq0[4:0]),
        .rx_dma1(rx_drq1[4:0]),
        .tx_dma1(tx_drq1[4:0]),
        .clip(clip_detect[4:0]));
    defparam bI2S.ClockSyncMode = 1;
    defparam bI2S.DataBits = 16;
    defparam bI2S.Direction = 2;
    defparam bI2S.EnableClipDetect = 0;
    defparam bI2S.EnableRxByteSwap = 0;
    defparam bI2S.EnableTxByteSwap = 0;
    defparam bI2S.NumRxChannels = 2;
    defparam bI2S.NumTxChannels = 2;
    defparam bI2S.RxDataInterleaving = 1;
    defparam bI2S.StaticBitResolution = 1;
    defparam bI2S.TxDataInterleaving = 1;
    defparam bI2S.WordSelect = 64;


    assign rx_line[4:0] = sdi;

    assign sdo = tx_line[4:0];

    assign rx_dma0 = rx_drq0[4:0];

    assign rx_dma1 = rx_drq1[4:0];

    assign tx_dma0 = tx_drq0[4:0];

    assign tx_dma1 = tx_drq1[4:0];

    assign clip = clip_detect[4:0];


endmodule

// top
module top ;

          wire  Net_50;
          wire  Net_49;
          wire  Net_46;
          wire [0:0] Net_53;
          wire  Net_44;
          wire  Net_43;
          wire [0:0] Net_42;
          wire [0:0] Net_41;
          wire [0:0] Net_52;
          wire [0:0] Net_51;
          wire [0:0] Net_135;
          wire  Net_164;
          wire [0:0] Net_15;
          wire  Net_167;
          wire  Net_168;

    I2S_v2_70_0 I2S_1 (
        .clock(Net_164),
        .sdi(5'b0),
        .sck(Net_168),
        .ws(Net_167),
        .sdo(Net_15[0:0]),
        .rx_dma0(Net_52[0:0]),
        .rx_dma1(Net_41[0:0]),
        .tx_dma0(Net_135[0:0]),
        .tx_dma1(Net_42[0:0]),
        .rx_interrupt(Net_43),
        .tx_interrupt(Net_44),
        .clip(Net_53[0:0]));


	cy_clock_v1_0
		#(.id("10da4bec-b9fa-46fe-9675-06a10da902d4"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("166666666.666667"),
		  .is_direct(0),
		  .is_digital(1))
		clock
		 (.clock_out(Net_164));



	cy_dma_v1_0
		#(.drq_type(2'b01))
		TxDMA
		 (.drq(Net_135[0:0]),
		  .trq(1'b0),
		  .nrq(Net_50));


	wire [0:0] tmpOE__SDO_net;
	wire [0:0] tmpFB_0__SDO_net;
	wire [0:0] tmpIO_0__SDO_net;
	wire [0:0] tmpINTERRUPT_0__SDO_net;
	electrical [0:0] tmpSIOVREF__SDO_net;

	cy_psoc3_pins_v1_10
		#(.id("bbe7756e-00e6-49dc-9ba6-204ca62f566d"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		SDO
		 (.oe(tmpOE__SDO_net),
		  .y({Net_15[0:0]}),
		  .fb({tmpFB_0__SDO_net[0:0]}),
		  .io({tmpIO_0__SDO_net[0:0]}),
		  .siovref(tmpSIOVREF__SDO_net),
		  .interrupt({tmpINTERRUPT_0__SDO_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SDO_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__SCK_net;
	wire [0:0] tmpFB_0__SCK_net;
	wire [0:0] tmpIO_0__SCK_net;
	wire [0:0] tmpINTERRUPT_0__SCK_net;
	electrical [0:0] tmpSIOVREF__SCK_net;

	cy_psoc3_pins_v1_10
		#(.id("88141c2d-0163-4f66-a8ce-8826769f2f78"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		SCK
		 (.oe(tmpOE__SCK_net),
		  .y({Net_168}),
		  .fb({tmpFB_0__SCK_net[0:0]}),
		  .io({tmpIO_0__SCK_net[0:0]}),
		  .siovref(tmpSIOVREF__SCK_net),
		  .interrupt({tmpINTERRUPT_0__SCK_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SCK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__WS_net;
	wire [0:0] tmpFB_0__WS_net;
	wire [0:0] tmpIO_0__WS_net;
	wire [0:0] tmpINTERRUPT_0__WS_net;
	electrical [0:0] tmpSIOVREF__WS_net;

	cy_psoc3_pins_v1_10
		#(.id("1977f7ec-b48d-4305-9ab9-fb40cb17f7da"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		WS
		 (.oe(tmpOE__WS_net),
		  .y({Net_167}),
		  .fb({tmpFB_0__WS_net[0:0]}),
		  .io({tmpIO_0__WS_net[0:0]}),
		  .siovref(tmpSIOVREF__WS_net),
		  .interrupt({tmpINTERRUPT_0__WS_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__WS_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};



endmodule

