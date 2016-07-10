// ======================================================================
// PSoC5_SPI_Master_DSP.v generated from TopDesign.cysch
// 07/09/2016 at 21:11
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
// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: B_SPI_Master_v2_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_SPI_Master_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_SPI_Master_v2_50\B_SPI_Master_v2_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_SPI_Master_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_SPI_Master_v2_50\B_SPI_Master_v2_50.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// SPI_Master_v2_50(BidirectMode=false, ClockInternal=false, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, DesiredBitRate=500000, HighSpeedMode=false, InternalClockUsed=0, InternalInterruptEnabled=0, InternalRxInterruptEnabled=0, InternalTxInterruptEnabled=1, InterruptOnByteComplete=false, InterruptOnRXFull=false, InterruptOnRXNotEmpty=false, InterruptOnRXOverrun=false, InterruptOnSPIDone=false, InterruptOnSPIIdle=false, InterruptOnTXEmpty=false, InterruptOnTXNotFull=true, IntOnByteComp=0, IntOnRXFull=0, IntOnRXNotEmpty=0, IntOnRXOver=0, IntOnSPIDone=0, IntOnSPIIdle=0, IntOnTXEmpty=0, IntOnTXNotFull=1, Mode=4, ModeUseZero=0, NumberOfDataBits=8, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, RxBufferSize=4, ShiftDir=0, TxBufferSize=255, UseInternalInterrupt=false, UseRxInternalInterrupt=false, UseTxInternalInterrupt=true, VerilogSectionReplacementString=sR8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=SPI_Master_v2_50, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=SPIM, CY_INSTANCE_SHORT_NAME=SPIM, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=50, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 SP2, INSTANCE_NAME=SPIM, )
module SPI_Master_v2_50_0 (
    clock,
    reset,
    miso,
    sclk,
    mosi,
    ss,
    rx_interrupt,
    sdat,
    tx_interrupt);
    input       clock;
    input       reset;
    input       miso;
    output      sclk;
    output      mosi;
    output      ss;
    output      rx_interrupt;
    inout       sdat;
    output      tx_interrupt;

    parameter BidirectMode = 0;
    parameter HighSpeedMode = 0;
    parameter NumberOfDataBits = 8;
    parameter ShiftDir = 0;

          wire  Net_289;
          wire  Net_257;
          wire  Net_288;
          wire  Net_294;
          wire  Net_161;
          wire  Net_244;
          wire  Net_273;
          wire  Net_276;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_276 = clock;

    B_SPI_Master_v2_50 BSPIM (
        .sclk(sclk),
        .ss(ss),
        .miso(Net_244),
        .clock(Net_276),
        .reset(Net_273),
        .rx_interpt(rx_interrupt),
        .tx_enable(Net_294),
        .mosi(mosi),
        .tx_interpt(tx_interrupt));
    defparam BSPIM.BidirectMode = 0;
    defparam BSPIM.HighSpeedMode = 0;
    defparam BSPIM.ModeCPHA = 1;
    defparam BSPIM.ModePOL = 1;
    defparam BSPIM.NumberOfDataBits = 8;
    defparam BSPIM.ShiftDir = 0;

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_244 = miso;


	cy_isr_v1_0
		#(.int_type(2'b10))
		TxInternalInterrupt
		 (.int_signal(tx_interrupt));


	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_273 = Net_289;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_289));



endmodule

// USBFS_v3_0(AudioDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="Audio">\r\n      <Nodes>\r\n        <DescriptorNode Key="Interface923">\r\n          <m_value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>MacPCAudioControlOutWithIntStat</DisplayName>\r\n          </m_value>\r\n          <Value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>MacPCAudioControlOutWithIntStat</DisplayName>\r\n          </Value>\r\n          <Nodes>\r\n            <DescriptorNode Key="USBDescriptor922">\r\n              <m_value d8p1:type="CyAudioInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>900</iwInterface>\r\n                <bInterfaceClass>1</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>0</bInterfaceNumber>\r\n                <bNumEndpoints>1</bNumEndpoints>\r\n                <bInterfaceSubClass>1</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>1</iInterface>\r\n                <sInterface>FreeDSP</sInterface>\r\n              </m_value>\r\n              <Value d8p1:type="CyAudioInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>900</iwInterface>\r\n                <bInterfaceClass>1</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>0</bInterfaceNumber>\r\n                <bNumEndpoints>1</bNumEndpoints>\r\n                <bInterfaceSubClass>1</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>1</iInterface>\r\n                <sInterface>FreeDSP</sInterface>\r\n              </Value>\r\n              <Nodes>\r\n                <DescriptorNode Key="USBDescriptor924">\r\n                  <m_value d10p1:type="CyACHeaderDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                    <bcdADC>256</bcdADC>\r\n                    <wTotalLength>38</wTotalLength>\r\n                    <bInCollection>1</bInCollection>\r\n                    <baInterfaceNr>AQ==</baInterfaceNr>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyACHeaderDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                    <bcdADC>256</bcdADC>\r\n                    <wTotalLength>38</wTotalLength>\r\n                    <bInCollection>1</bInCollection>\r\n                    <baInterfaceNr>AQ==</baInterfaceNr>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor925">\r\n                  <m_value d10p1:type="CyACFeatureUnitDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>8</bLength>\r\n                    <iwFeature>0</iwFeature>\r\n                    <bDescriptorSubtype>FEATURE_UNIT</bDescriptorSubtype>\r\n                    <bUnitID>2</bUnitID>\r\n                    <bSourceID>1</bSourceID>\r\n                    <bmaControls>\r\n                      <unsignedInt>3</unsignedInt>\r\n                    </bmaControls>\r\n                    <iFeature>0</iFeature>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyACFeatureUnitDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>8</bLength>\r\n                    <iwFeature>0</iwFeature>\r\n                    <bDescriptorSubtype>FEATURE_UNIT</bDescriptorSubtype>\r\n                    <bUnitID>2</bUnitID>\r\n                    <bSourceID>1</bSourceID>\r\n                    <bmaControls>\r\n                      <unsignedInt>3</unsignedInt>\r\n                    </bmaControls>\r\n                    <iFeature>0</iFeature>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor926">\r\n                  <m_value d10p1:type="CyACInputTerminalDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>12</bLength>\r\n                    <iwChannelNames>0</iwChannelNames>\r\n                    <iwTerminal>904</iwTerminal>\r\n                    <bDescriptorSubtype>INPUT_TERMINAL</bDescriptorSubtype>\r\n                    <bTerminalID>1</bTerminalID>\r\n                    <wTerminalType>257</wTerminalType>\r\n                    <bNrChannels>2</bNrChannels>\r\n                    <wChannelConfig>3</wChannelConfig>\r\n                    <iChannelNames>0</iChannelNames>\r\n                    <iTerminal>5</iTerminal>\r\n                    <sTerminal>USB Streaming</sTerminal>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyACInputTerminalDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>12</bLength>\r\n                    <iwChannelNames>0</iwChannelNames>\r\n                    <iwTerminal>904</iwTerminal>\r\n                    <bDescriptorSubtype>INPUT_TERMINAL</bDescriptorSubtype>\r\n                    <bTerminalID>1</bTerminalID>\r\n                    <wTerminalType>257</wTerminalType>\r\n                    <bNrChannels>2</bNrChannels>\r\n                    <wChannelConfig>3</wChannelConfig>\r\n                    <iChannelNames>0</iChannelNames>\r\n                    <iTerminal>5</iTerminal>\r\n                    <sTerminal>USB Streaming</sTerminal>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor927">\r\n                  <m_value d10p1:type="CyACOutputTerminalDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <iwTerminal>920</iwTerminal>\r\n                    <bDescriptorSubtype>OUTPUT_TERMINAL</bDescriptorSubtype>\r\n                    <bTerminalID>3</bTerminalID>\r\n                    <wTerminalType>769</wTerminalType>\r\n                    <bSourceID>2</bSourceID>\r\n                    <iTerminal>7</iTerminal>\r\n                    <sTerminal>Speaker</sTerminal>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyACOutputTerminalDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <iwTerminal>920</iwTerminal>\r\n                    <bDescriptorSubtype>OUTPUT_TERMINAL</bDescriptorSubtype>\r\n                    <bTerminalID>3</bTerminalID>\r\n                    <wTerminalType>769</wTerminalType>\r\n                    <bSourceID>2</bSourceID>\r\n                    <iTerminal>7</iTerminal>\r\n                    <sTerminal>Speaker</sTerminal>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor928">\r\n                  <m_value d10p1:type="CyAudioEndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bInterval>30</bInterval>\r\n                    <bEndpointAddress>134</bEndpointAddress>\r\n                    <bmAttributes>3</bmAttributes>\r\n                    <wMaxPacketSize>2</wMaxPacketSize>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyAudioEndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bInterval>30</bInterval>\r\n                    <bEndpointAddress>134</bEndpointAddress>\r\n                    <bmAttributes>3</bmAttributes>\r\n                    <wMaxPacketSize>2</wMaxPacketSize>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n              </Nodes>\r\n            </DescriptorNode>\r\n          </Nodes>\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="Interface930">\r\n          <m_value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>MacPCAudioStreamingOut</DisplayName>\r\n          </m_value>\r\n          <Value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>MacPCAudioStreamingOut</DisplayName>\r\n          </Value>\r\n          <Nodes>\r\n            <DescriptorNode Key="USBDescriptor929">\r\n              <m_value d8p1:type="CyAudioInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>900</iwInterface>\r\n                <bInterfaceClass>1</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>1</bInterfaceNumber>\r\n                <bNumEndpoints>0</bNumEndpoints>\r\n                <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>1</iInterface>\r\n                <sInterface>FreeDSP</sInterface>\r\n              </m_value>\r\n              <Value d8p1:type="CyAudioInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>900</iwInterface>\r\n                <bInterfaceClass>1</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>1</bInterfaceNumber>\r\n                <bNumEndpoints>0</bNumEndpoints>\r\n                <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>1</iInterface>\r\n                <sInterface>FreeDSP</sInterface>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor931">\r\n              <m_value d8p1:type="CyAudioInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>921</iwInterface>\r\n                <bInterfaceClass>1</bInterfaceClass>\r\n                <bAlternateSetting>1</bAlternateSetting>\r\n                <bInterfaceNumber>1</bInterfaceNumber>\r\n                <bNumEndpoints>1</bNumEndpoints>\r\n                <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>8</iInterface>\r\n                <sInterface>Active 16 bit</sInterface>\r\n              </m_value>\r\n              <Value d8p1:type="CyAudioInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>921</iwInterface>\r\n                <bInterfaceClass>1</bInterfaceClass>\r\n                <bAlternateSetting>1</bAlternateSetting>\r\n                <bInterfaceNumber>1</bInterfaceNumber>\r\n                <bNumEndpoints>1</bNumEndpoints>\r\n                <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>8</iInterface>\r\n                <sInterface>Active 16 bit</sInterface>\r\n              </Value>\r\n              <Nodes>\r\n                <DescriptorNode Key="USBDescriptor932">\r\n                  <m_value d10p1:type="CyASGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <bDescriptorSubtype>AS_GENERAL</bDescriptorSubtype>\r\n                    <bTerminalLink>1</bTerminalLink>\r\n                    <bDelay>1</bDelay>\r\n                    <wFormatTag>1</wFormatTag>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyASGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <bDescriptorSubtype>AS_GENERAL</bDescriptorSubtype>\r\n                    <bTerminalLink>1</bTerminalLink>\r\n                    <bDelay>1</bDelay>\r\n                    <wFormatTag>1</wFormatTag>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor933">\r\n                  <m_value d10p1:type="CyASFormatType1Descriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>17</bLength>\r\n                    <bDescriptorSubtype>FORMAT_TYPE</bDescriptorSubtype>\r\n                    <bFormatType>FORMAT_TYPE_1</bFormatType>\r\n                    <bSamFreqType>3</bSamFreqType>\r\n                    <tSamFreq>\r\n                      <unsignedInt>32000</unsignedInt>\r\n                      <unsignedInt>44100</unsignedInt>\r\n                      <unsignedInt>48000</unsignedInt>\r\n                    </tSamFreq>\r\n                    <bNrChannels>2</bNrChannels>\r\n                    <bSubframeSize>2</bSubframeSize>\r\n                    <bBitResolution>16</bBitResolution>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyASFormatType1Descriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>17</bLength>\r\n                    <bDescriptorSubtype>FORMAT_TYPE</bDescriptorSubtype>\r\n                    <bFormatType>FORMAT_TYPE_1</bFormatType>\r\n                    <bSamFreqType>3</bSamFreqType>\r\n                    <tSamFreq>\r\n                      <unsignedInt>32000</unsignedInt>\r\n                      <unsignedInt>44100</unsignedInt>\r\n                      <unsignedInt>48000</unsignedInt>\r\n                    </tSamFreq>\r\n                    <bNrChannels>2</bNrChannels>\r\n                    <bSubframeSize>2</bSubframeSize>\r\n                    <bBitResolution>16</bBitResolution>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor934">\r\n                  <m_value d10p1:type="CyAudioEndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bInterval>1</bInterval>\r\n                    <bEndpointAddress>1</bEndpointAddress>\r\n                    <bmAttributes>13</bmAttributes>\r\n                    <wMaxPacketSize>192</wMaxPacketSize>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyAudioEndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bInterval>1</bInterval>\r\n                    <bEndpointAddress>1</bEndpointAddress>\r\n                    <bmAttributes>13</bmAttributes>\r\n                    <wMaxPacketSize>192</wMaxPacketSize>\r\n                  </Value>\r\n                  <Nodes>\r\n                    <DescriptorNode Key="USBDescriptor935">\r\n                      <m_value d12p1:type="CyASEndpointDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                        <bLength>7</bLength>\r\n                        <bDescriptorSubtype>EP_GENERAL</bDescriptorSubtype>\r\n                        <bmAttributes>1</bmAttributes>\r\n                        <bLockDelayUnits>1</bLockDelayUnits>\r\n                        <wLockDelay>1</wLockDelay>\r\n                      </m_value>\r\n                      <Value d12p1:type="CyASEndpointDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                        <bLength>7</bLength>\r\n                        <bDescriptorSubtype>EP_GENERAL</bDescriptorSubtype>\r\n                        <bmAttributes>1</bmAttributes>\r\n                        <bLockDelayUnits>1</bLockDelayUnits>\r\n                        <wLockDelay>1</wLockDelay>\r\n                      </Value>\r\n                      <Nodes />\r\n                    </DescriptorNode>\r\n                  </Nodes>\r\n                </DescriptorNode>\r\n              </Nodes>\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor936">\r\n              <m_value d8p1:type="CyAudioInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>905</iwInterface>\r\n                <bInterfaceClass>1</bInterfaceClass>\r\n                <bAlternateSetting>2</bAlternateSetting>\r\n                <bInterfaceNumber>1</bInterfaceNumber>\r\n                <bNumEndpoints>1</bNumEndpoints>\r\n                <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>6</iInterface>\r\n                <sInterface>Active 24 bit</sInterface>\r\n              </m_value>\r\n              <Value d8p1:type="CyAudioInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>905</iwInterface>\r\n                <bInterfaceClass>1</bInterfaceClass>\r\n                <bAlternateSetting>2</bAlternateSetting>\r\n                <bInterfaceNumber>1</bInterfaceNumber>\r\n                <bNumEndpoints>1</bNumEndpoints>\r\n                <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>6</iInterface>\r\n                <sInterface>Active 24 bit</sInterface>\r\n              </Value>\r\n              <Nodes>\r\n                <DescriptorNode Key="USBDescriptor937">\r\n                  <m_value d10p1:type="CyASGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <bDescriptorSubtype>AS_GENERAL</bDescriptorSubtype>\r\n                    <bTerminalLink>1</bTerminalLink>\r\n                    <bDelay>1</bDelay>\r\n                    <wFormatTag>1</wFormatTag>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyASGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <bDescriptorSubtype>AS_GENERAL</bDescriptorSubtype>\r\n                    <bTerminalLink>1</bTerminalLink>\r\n                    <bDelay>1</bDelay>\r\n                    <wFormatTag>1</wFormatTag>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor938">\r\n                  <m_value d10p1:type="CyASFormatType1Descriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>17</bLength>\r\n                    <bDescriptorSubtype>FORMAT_TYPE</bDescriptorSubtype>\r\n                    <bFormatType>FORMAT_TYPE_1</bFormatType>\r\n                    <bSamFreqType>3</bSamFreqType>\r\n                    <tLowerSamFreq>32000</tLowerSamFreq>\r\n                    <tUpperSamFreq>32000</tUpperSamFreq>\r\n                    <tSamFreq>\r\n                      <unsignedInt>32000</unsignedInt>\r\n                      <unsignedInt>44100</unsignedInt>\r\n                      <unsignedInt>48000</unsignedInt>\r\n                    </tSamFreq>\r\n                    <bNrChannels>2</bNrChannels>\r\n                    <bSubframeSize>3</bSubframeSize>\r\n                    <bBitResolution>24</bBitResolution>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyASFormatType1Descriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>17</bLength>\r\n                    <bDescriptorSubtype>FORMAT_TYPE</bDescriptorSubtype>\r\n                    <bFormatType>FORMAT_TYPE_1</bFormatType>\r\n                    <bSamFreqType>3</bSamFreqType>\r\n                    <tLowerSamFreq>32000</tLowerSamFreq>\r\n                    <tUpperSamFreq>32000</tUpperSamFreq>\r\n                    <tSamFreq>\r\n                      <unsignedInt>32000</unsignedInt>\r\n                      <unsignedInt>44100</unsignedInt>\r\n                      <unsignedInt>48000</unsignedInt>\r\n                    </tSamFreq>\r\n                    <bNrChannels>2</bNrChannels>\r\n                    <bSubframeSize>3</bSubframeSize>\r\n                    <bBitResolution>24</bBitResolution>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor939">\r\n                  <m_value d10p1:type="CyAudioEndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bInterval>1</bInterval>\r\n                    <bEndpointAddress>1</bEndpointAddress>\r\n                    <bmAttributes>13</bmAttributes>\r\n                    <wMaxPacketSize>288</wMaxPacketSize>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyAudioEndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bInterval>1</bInterval>\r\n                    <bEndpointAddress>1</bEndpointAddress>\r\n                    <bmAttributes>13</bmAttributes>\r\n                    <wMaxPacketSize>288</wMaxPacketSize>\r\n                  </Value>\r\n                  <Nodes>\r\n                    <DescriptorNode Key="USBDescriptor940">\r\n                      <m_value d12p1:type="CyASEndpointDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                        <bLength>7</bLength>\r\n                        <bDescriptorSubtype>EP_GENERAL</bDescriptorSubtype>\r\n                        <bmAttributes>1</bmAttributes>\r\n                        <bLockDelayUnits>1</bLockDelayUnits>\r\n                        <wLockDelay>1</wLockDelay>\r\n                      </m_value>\r\n                      <Value d12p1:type="CyASEndpointDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                        <bLength>7</bLength>\r\n                        <bDescriptorSubtype>EP_GENERAL</bDescriptorSubtype>\r\n                        <bmAttributes>1</bmAttributes>\r\n                        <bLockDelayUnits>1</bLockDelayUnits>\r\n                        <wLockDelay>1</wLockDelay>\r\n                      </Value>\r\n                      <Nodes />\r\n                    </DescriptorNode>\r\n                  </Nodes>\r\n                </DescriptorNode>\r\n              </Nodes>\r\n            </DescriptorNode>\r\n          </Nodes>\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, CDCDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="CDC">\r\n      <Nodes />\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, DeviceDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="Device">\r\n      <Nodes>\r\n        <DescriptorNode Key="USBDescriptor895">\r\n          <m_value d6p1:type="DeviceDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>DEVICE</bDescriptorType>\r\n            <bLength>18</bLength>\r\n            <iwManufacturer>900</iwManufacturer>\r\n            <iwProduct>901</iwProduct>\r\n            <sManufacturer>FreeDSP</sManufacturer>\r\n            <sProduct>Insanity</sProduct>\r\n            <bDeviceClass>0</bDeviceClass>\r\n            <bDeviceSubClass>0</bDeviceSubClass>\r\n            <bDeviceProtocol>0</bDeviceProtocol>\r\n            <bMaxPacketSize0>0</bMaxPacketSize0>\r\n            <idVendor>1204</idVendor>\r\n            <idProduct>32849</idProduct>\r\n            <bcdDevice>0</bcdDevice>\r\n            <bcdUSB>512</bcdUSB>\r\n            <iManufacturer>1</iManufacturer>\r\n            <iProduct>2</iProduct>\r\n            <iSerialNumber>0</iSerialNumber>\r\n            <bNumConfigurations>1</bNumConfigurations>\r\n            <bMemoryMgmt>0</bMemoryMgmt>\r\n            <bMemoryAlloc>0</bMemoryAlloc>\r\n          </m_value>\r\n          <Value d6p1:type="DeviceDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>DEVICE</bDescriptorType>\r\n            <bLength>18</bLength>\r\n            <iwManufacturer>900</iwManufacturer>\r\n            <iwProduct>901</iwProduct>\r\n            <sManufacturer>FreeDSP</sManufacturer>\r\n            <sProduct>Insanity</sProduct>\r\n            <bDeviceClass>0</bDeviceClass>\r\n            <bDeviceSubClass>0</bDeviceSubClass>\r\n            <bDeviceProtocol>0</bDeviceProtocol>\r\n            <bMaxPacketSize0>0</bMaxPacketSize0>\r\n            <idVendor>1204</idVendor>\r\n            <idProduct>32849</idProduct>\r\n            <bcdDevice>0</bcdDevice>\r\n            <bcdUSB>512</bcdUSB>\r\n            <iManufacturer>1</iManufacturer>\r\n            <iProduct>2</iProduct>\r\n            <iSerialNumber>0</iSerialNumber>\r\n            <bNumConfigurations>1</bNumConfigurations>\r\n            <bMemoryMgmt>0</bMemoryMgmt>\r\n            <bMemoryAlloc>0</bMemoryAlloc>\r\n          </Value>\r\n          <Nodes>\r\n            <DescriptorNode Key="USBDescriptor896">\r\n              <m_value d8p1:type="ConfigDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>CONFIGURATION</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwConfiguration>0</iwConfiguration>\r\n                <wTotalLength>172</wTotalLength>\r\n                <bNumInterfaces>2</bNumInterfaces>\r\n                <bConfigurationValue>0</bConfigurationValue>\r\n                <iConfiguration>0</iConfiguration>\r\n                <bmAttributes>128</bmAttributes>\r\n                <bMaxPower>25</bMaxPower>\r\n              </m_value>\r\n              <Value d8p1:type="ConfigDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>CONFIGURATION</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwConfiguration>0</iwConfiguration>\r\n                <wTotalLength>172</wTotalLength>\r\n                <bNumInterfaces>2</bNumInterfaces>\r\n                <bConfigurationValue>0</bConfigurationValue>\r\n                <iConfiguration>0</iConfiguration>\r\n                <bmAttributes>128</bmAttributes>\r\n                <bMaxPower>25</bMaxPower>\r\n              </Value>\r\n              <Nodes>\r\n                <DescriptorNode Key="Interface923">\r\n                  <m_value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>MacPCAudioControlOutWithIntStat</DisplayName>\r\n                  </m_value>\r\n                  <Value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>MacPCAudioControlOutWithIntStat</DisplayName>\r\n                  </Value>\r\n                  <Nodes>\r\n                    <DescriptorNode Key="USBDescriptor922">\r\n                      <m_value d12p1:type="CyAudioInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>900</iwInterface>\r\n                        <bInterfaceClass>1</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>0</bInterfaceNumber>\r\n                        <bNumEndpoints>1</bNumEndpoints>\r\n                        <bInterfaceSubClass>1</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>1</iInterface>\r\n                        <sInterface>FreeDSP</sInterface>\r\n                      </m_value>\r\n                      <Value d12p1:type="CyAudioInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>900</iwInterface>\r\n                        <bInterfaceClass>1</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>0</bInterfaceNumber>\r\n                        <bNumEndpoints>1</bNumEndpoints>\r\n                        <bInterfaceSubClass>1</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>1</iInterface>\r\n                        <sInterface>FreeDSP</sInterface>\r\n                      </Value>\r\n                      <Nodes>\r\n                        <DescriptorNode Key="USBDescriptor924">\r\n                          <m_value d14p1:type="CyACHeaderDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                            <bcdADC>256</bcdADC>\r\n                            <wTotalLength>38</wTotalLength>\r\n                            <bInCollection>1</bInCollection>\r\n                            <baInterfaceNr>AQ==</baInterfaceNr>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyACHeaderDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                            <bcdADC>256</bcdADC>\r\n                            <wTotalLength>38</wTotalLength>\r\n                            <bInCollection>1</bInCollection>\r\n                            <baInterfaceNr>AQ==</baInterfaceNr>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor925">\r\n                          <m_value d14p1:type="CyACFeatureUnitDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>8</bLength>\r\n                            <iwFeature>0</iwFeature>\r\n                            <bDescriptorSubtype>FEATURE_UNIT</bDescriptorSubtype>\r\n                            <bUnitID>2</bUnitID>\r\n                            <bSourceID>1</bSourceID>\r\n                            <bmaControls>\r\n                              <unsignedInt>3</unsignedInt>\r\n                            </bmaControls>\r\n                            <iFeature>0</iFeature>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyACFeatureUnitDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>8</bLength>\r\n                            <iwFeature>0</iwFeature>\r\n                            <bDescriptorSubtype>FEATURE_UNIT</bDescriptorSubtype>\r\n                            <bUnitID>2</bUnitID>\r\n                            <bSourceID>1</bSourceID>\r\n                            <bmaControls>\r\n                              <unsignedInt>3</unsignedInt>\r\n                            </bmaControls>\r\n                            <iFeature>0</iFeature>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor926">\r\n                          <m_value d14p1:type="CyACInputTerminalDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>12</bLength>\r\n                            <iwChannelNames>0</iwChannelNames>\r\n                            <iwTerminal>904</iwTerminal>\r\n                            <bDescriptorSubtype>INPUT_TERMINAL</bDescriptorSubtype>\r\n                            <bTerminalID>1</bTerminalID>\r\n                            <wTerminalType>257</wTerminalType>\r\n                            <bNrChannels>2</bNrChannels>\r\n                            <wChannelConfig>3</wChannelConfig>\r\n                            <iChannelNames>0</iChannelNames>\r\n                            <iTerminal>5</iTerminal>\r\n                            <sTerminal>USB Streaming</sTerminal>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyACInputTerminalDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>12</bLength>\r\n                            <iwChannelNames>0</iwChannelNames>\r\n                            <iwTerminal>904</iwTerminal>\r\n                            <bDescriptorSubtype>INPUT_TERMINAL</bDescriptorSubtype>\r\n                            <bTerminalID>1</bTerminalID>\r\n                            <wTerminalType>257</wTerminalType>\r\n                            <bNrChannels>2</bNrChannels>\r\n                            <wChannelConfig>3</wChannelConfig>\r\n                            <iChannelNames>0</iChannelNames>\r\n                            <iTerminal>5</iTerminal>\r\n                            <sTerminal>USB Streaming</sTerminal>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor927">\r\n                          <m_value d14p1:type="CyACOutputTerminalDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <iwTerminal>920</iwTerminal>\r\n                            <bDescriptorSubtype>OUTPUT_TERMINAL</bDescriptorSubtype>\r\n                            <bTerminalID>3</bTerminalID>\r\n                            <wTerminalType>769</wTerminalType>\r\n                            <bSourceID>2</bSourceID>\r\n                            <iTerminal>7</iTerminal>\r\n                            <sTerminal>Speaker</sTerminal>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyACOutputTerminalDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <iwTerminal>920</iwTerminal>\r\n                            <bDescriptorSubtype>OUTPUT_TERMINAL</bDescriptorSubtype>\r\n                            <bTerminalID>3</bTerminalID>\r\n                            <wTerminalType>769</wTerminalType>\r\n                            <bSourceID>2</bSourceID>\r\n                            <iTerminal>7</iTerminal>\r\n                            <sTerminal>Speaker</sTerminal>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor928">\r\n                          <m_value d14p1:type="CyAudioEndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bInterval>30</bInterval>\r\n                            <bEndpointAddress>134</bEndpointAddress>\r\n                            <bmAttributes>3</bmAttributes>\r\n                            <wMaxPacketSize>2</wMaxPacketSize>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyAudioEndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bInterval>30</bInterval>\r\n                            <bEndpointAddress>134</bEndpointAddress>\r\n                            <bmAttributes>3</bmAttributes>\r\n                            <wMaxPacketSize>2</wMaxPacketSize>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                      </Nodes>\r\n                    </DescriptorNode>\r\n                  </Nodes>\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="Interface930">\r\n                  <m_value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>MacPCAudioStreamingOut</DisplayName>\r\n                  </m_value>\r\n                  <Value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>MacPCAudioStreamingOut</DisplayName>\r\n                  </Value>\r\n                  <Nodes>\r\n                    <DescriptorNode Key="USBDescriptor929">\r\n                      <m_value d12p1:type="CyAudioInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>900</iwInterface>\r\n                        <bInterfaceClass>1</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>1</bInterfaceNumber>\r\n                        <bNumEndpoints>0</bNumEndpoints>\r\n                        <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>1</iInterface>\r\n                        <sInterface>FreeDSP</sInterface>\r\n                      </m_value>\r\n                      <Value d12p1:type="CyAudioInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>900</iwInterface>\r\n                        <bInterfaceClass>1</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>1</bInterfaceNumber>\r\n                        <bNumEndpoints>0</bNumEndpoints>\r\n                        <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>1</iInterface>\r\n                        <sInterface>FreeDSP</sInterface>\r\n                      </Value>\r\n                      <Nodes />\r\n                    </DescriptorNode>\r\n                    <DescriptorNode Key="USBDescriptor931">\r\n                      <m_value d12p1:type="CyAudioInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>921</iwInterface>\r\n                        <bInterfaceClass>1</bInterfaceClass>\r\n                        <bAlternateSetting>1</bAlternateSetting>\r\n                        <bInterfaceNumber>1</bInterfaceNumber>\r\n                        <bNumEndpoints>1</bNumEndpoints>\r\n                        <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>8</iInterface>\r\n                        <sInterface>Active 16 bit</sInterface>\r\n                      </m_value>\r\n                      <Value d12p1:type="CyAudioInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>921</iwInterface>\r\n                        <bInterfaceClass>1</bInterfaceClass>\r\n                        <bAlternateSetting>1</bAlternateSetting>\r\n                        <bInterfaceNumber>1</bInterfaceNumber>\r\n                        <bNumEndpoints>1</bNumEndpoints>\r\n                        <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>8</iInterface>\r\n                        <sInterface>Active 16 bit</sInterface>\r\n                      </Value>\r\n                      <Nodes>\r\n                        <DescriptorNode Key="USBDescriptor932">\r\n                          <m_value d14p1:type="CyASGeneralDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <bDescriptorSubtype>AS_GENERAL</bDescriptorSubtype>\r\n                            <bTerminalLink>1</bTerminalLink>\r\n                            <bDelay>1</bDelay>\r\n                            <wFormatTag>1</wFormatTag>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyASGeneralDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <bDescriptorSubtype>AS_GENERAL</bDescriptorSubtype>\r\n                            <bTerminalLink>1</bTerminalLink>\r\n                            <bDelay>1</bDelay>\r\n                            <wFormatTag>1</wFormatTag>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor933">\r\n                          <m_value d14p1:type="CyASFormatType1Descriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>17</bLength>\r\n                            <bDescriptorSubtype>FORMAT_TYPE</bDescriptorSubtype>\r\n                            <bFormatType>FORMAT_TYPE_1</bFormatType>\r\n                            <bSamFreqType>3</bSamFreqType>\r\n                            <tSamFreq>\r\n                              <unsignedInt>32000</unsignedInt>\r\n                              <unsignedInt>44100</unsignedInt>\r\n                              <unsignedInt>48000</unsignedInt>\r\n                            </tSamFreq>\r\n                            <bNrChannels>2</bNrChannels>\r\n                            <bSubframeSize>2</bSubframeSize>\r\n                            <bBitResolution>16</bBitResolution>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyASFormatType1Descriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>17</bLength>\r\n                            <bDescriptorSubtype>FORMAT_TYPE</bDescriptorSubtype>\r\n                            <bFormatType>FORMAT_TYPE_1</bFormatType>\r\n                            <bSamFreqType>3</bSamFreqType>\r\n                            <tSamFreq>\r\n                              <unsignedInt>32000</unsignedInt>\r\n                              <unsignedInt>44100</unsignedInt>\r\n                              <unsignedInt>48000</unsignedInt>\r\n                            </tSamFreq>\r\n                            <bNrChannels>2</bNrChannels>\r\n                            <bSubframeSize>2</bSubframeSize>\r\n                            <bBitResolution>16</bBitResolution>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor934">\r\n                          <m_value d14p1:type="CyAudioEndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bInterval>1</bInterval>\r\n                            <bEndpointAddress>1</bEndpointAddress>\r\n                            <bmAttributes>13</bmAttributes>\r\n                            <wMaxPacketSize>192</wMaxPacketSize>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyAudioEndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bInterval>1</bInterval>\r\n                            <bEndpointAddress>1</bEndpointAddress>\r\n                            <bmAttributes>13</bmAttributes>\r\n                            <wMaxPacketSize>192</wMaxPacketSize>\r\n                          </Value>\r\n                          <Nodes>\r\n                            <DescriptorNode Key="USBDescriptor935">\r\n                              <m_value d16p1:type="CyASEndpointDescriptor" xmlns:d16p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                                <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                                <bLength>7</bLength>\r\n                                <bDescriptorSubtype>EP_GENERAL</bDescriptorSubtype>\r\n                                <bmAttributes>1</bmAttributes>\r\n                                <bLockDelayUnits>1</bLockDelayUnits>\r\n                                <wLockDelay>1</wLockDelay>\r\n                              </m_value>\r\n                              <Value d16p1:type="CyASEndpointDescriptor" xmlns:d16p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                                <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                                <bLength>7</bLength>\r\n                                <bDescriptorSubtype>EP_GENERAL</bDescriptorSubtype>\r\n                                <bmAttributes>1</bmAttributes>\r\n                                <bLockDelayUnits>1</bLockDelayUnits>\r\n                                <wLockDelay>1</wLockDelay>\r\n                              </Value>\r\n                              <Nodes />\r\n                            </DescriptorNode>\r\n                          </Nodes>\r\n                        </DescriptorNode>\r\n                      </Nodes>\r\n                    </DescriptorNode>\r\n                    <DescriptorNode Key="USBDescriptor936">\r\n                      <m_value d12p1:type="CyAudioInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>905</iwInterface>\r\n                        <bInterfaceClass>1</bInterfaceClass>\r\n                        <bAlternateSetting>2</bAlternateSetting>\r\n                        <bInterfaceNumber>1</bInterfaceNumber>\r\n                        <bNumEndpoints>1</bNumEndpoints>\r\n                        <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>6</iInterface>\r\n                        <sInterface>Active 24 bit</sInterface>\r\n                      </m_value>\r\n                      <Value d12p1:type="CyAudioInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>905</iwInterface>\r\n                        <bInterfaceClass>1</bInterfaceClass>\r\n                        <bAlternateSetting>2</bAlternateSetting>\r\n                        <bInterfaceNumber>1</bInterfaceNumber>\r\n                        <bNumEndpoints>1</bNumEndpoints>\r\n                        <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>6</iInterface>\r\n                        <sInterface>Active 24 bit</sInterface>\r\n                      </Value>\r\n                      <Nodes>\r\n                        <DescriptorNode Key="USBDescriptor937">\r\n                          <m_value d14p1:type="CyASGeneralDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <bDescriptorSubtype>AS_GENERAL</bDescriptorSubtype>\r\n                            <bTerminalLink>1</bTerminalLink>\r\n                            <bDelay>1</bDelay>\r\n                            <wFormatTag>1</wFormatTag>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyASGeneralDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <bDescriptorSubtype>AS_GENERAL</bDescriptorSubtype>\r\n                            <bTerminalLink>1</bTerminalLink>\r\n                            <bDelay>1</bDelay>\r\n                            <wFormatTag>1</wFormatTag>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor938">\r\n                          <m_value d14p1:type="CyASFormatType1Descriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>17</bLength>\r\n                            <bDescriptorSubtype>FORMAT_TYPE</bDescriptorSubtype>\r\n                            <bFormatType>FORMAT_TYPE_1</bFormatType>\r\n                            <bSamFreqType>3</bSamFreqType>\r\n                            <tLowerSamFreq>32000</tLowerSamFreq>\r\n                            <tUpperSamFreq>32000</tUpperSamFreq>\r\n                            <tSamFreq>\r\n                              <unsignedInt>32000</unsignedInt>\r\n                              <unsignedInt>44100</unsignedInt>\r\n                              <unsignedInt>48000</unsignedInt>\r\n                            </tSamFreq>\r\n                            <bNrChannels>2</bNrChannels>\r\n                            <bSubframeSize>3</bSubframeSize>\r\n                            <bBitResolution>24</bBitResolution>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyASFormatType1Descriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>17</bLength>\r\n                            <bDescriptorSubtype>FORMAT_TYPE</bDescriptorSubtype>\r\n                            <bFormatType>FORMAT_TYPE_1</bFormatType>\r\n                            <bSamFreqType>3</bSamFreqType>\r\n                            <tLowerSamFreq>32000</tLowerSamFreq>\r\n                            <tUpperSamFreq>32000</tUpperSamFreq>\r\n                            <tSamFreq>\r\n                              <unsignedInt>32000</unsignedInt>\r\n                              <unsignedInt>44100</unsignedInt>\r\n                              <unsignedInt>48000</unsignedInt>\r\n                            </tSamFreq>\r\n                            <bNrChannels>2</bNrChannels>\r\n                            <bSubframeSize>3</bSubframeSize>\r\n                            <bBitResolution>24</bBitResolution>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor939">\r\n                          <m_value d14p1:type="CyAudioEndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bInterval>1</bInterval>\r\n                            <bEndpointAddress>1</bEndpointAddress>\r\n                            <bmAttributes>13</bmAttributes>\r\n                            <wMaxPacketSize>288</wMaxPacketSize>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyAudioEndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bInterval>1</bInterval>\r\n                            <bEndpointAddress>1</bEndpointAddress>\r\n                            <bmAttributes>13</bmAttributes>\r\n                            <wMaxPacketSize>288</wMaxPacketSize>\r\n                          </Value>\r\n                          <Nodes>\r\n                            <DescriptorNode Key="USBDescriptor940">\r\n                              <m_value d16p1:type="CyASEndpointDescriptor" xmlns:d16p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                                <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                                <bLength>7</bLength>\r\n                                <bDescriptorSubtype>EP_GENERAL</bDescriptorSubtype>\r\n                                <bmAttributes>1</bmAttributes>\r\n                                <bLockDelayUnits>1</bLockDelayUnits>\r\n                                <wLockDelay>1</wLockDelay>\r\n                              </m_value>\r\n                              <Value d16p1:type="CyASEndpointDescriptor" xmlns:d16p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                                <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                                <bLength>7</bLength>\r\n                                <bDescriptorSubtype>EP_GENERAL</bDescriptorSubtype>\r\n                                <bmAttributes>1</bmAttributes>\r\n                                <bLockDelayUnits>1</bLockDelayUnits>\r\n                                <wLockDelay>1</wLockDelay>\r\n                              </Value>\r\n                              <Nodes />\r\n                            </DescriptorNode>\r\n                          </Nodes>\r\n                        </DescriptorNode>\r\n                      </Nodes>\r\n                    </DescriptorNode>\r\n                  </Nodes>\r\n                </DescriptorNode>\r\n              </Nodes>\r\n            </DescriptorNode>\r\n          </Nodes>\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, DmaChannelPriority=3, DW_Hide_DmaAuto=true, DW_Hide_Usbv2Regs=true, DW_RegSize=8, DW_USB_CHGDET_CTRL=CR0, DW_USB_INTR_CAUSE_HI=CR0, DW_USB_INTR_CAUSE_LO=CR0, DW_USB_INTR_CAUSE_MED=CR0, DW_USB_INTR_LVL_SEL=CR0, DW_USB_INTR_SIE=CR0, DW_USB_INTR_SIE_MASK=CR0, DW_USB_LPM_CTRL=CR0, DW_USB_LPM_STAT=CR0, DW_USB_POWER_CTRL=CR0, EnableBatteryChargDetect=false, EnableCDCApi=true, EnableMidiApi=true, endpointMA=0, endpointMM=0, epDMAautoOptimization=false, extern_cls=false, extern_vbus=true, extern_vnd=false, extJackCount=0, Gen16bitEpAccessApi=false, HandleMscRequests=true, HIDReportDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="HIDReport">\r\n      <Nodes />\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, isrGroupArbiter=0, isrGroupBusReset=2, isrGroupEp0=1, isrGroupEp1=1, isrGroupEp2=1, isrGroupEp3=1, isrGroupEp4=1, isrGroupEp5=1, isrGroupEp6=1, isrGroupEp7=1, isrGroupEp8=1, isrGroupLpm=0, isrGroupSof=2, M0S8USBDSS_BLOCK_COUNT_1=0, max_interfaces_num=2, MidiDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="Midi">\r\n      <Nodes />\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, Mode=false, mon_vbus=false, MscDescriptors=, MscLogicalUnitsNum=1, out_sof=false, Pid=F232, powerpad_vbus=false, PRIMITIVE_INSTANCE=USB, ProdactName=, ProdactRevision=, REG_SIZE=reg8, RemoveDmaAutoOpt=true, RemoveVbusPin=true, rm_arb_int=false, rm_dma_1=true, rm_dma_2=true, rm_dma_3=true, rm_dma_4=true, rm_dma_5=true, rm_dma_6=true, rm_dma_7=true, rm_dma_8=true, rm_dp_int=false, rm_ep_isr_0=false, rm_ep_isr_1=false, rm_ep_isr_2=true, rm_ep_isr_3=true, rm_ep_isr_4=true, rm_ep_isr_5=true, rm_ep_isr_6=false, rm_ep_isr_7=true, rm_ep_isr_8=true, rm_lpm_int=true, rm_ord_int=true, rm_sof_int=true, rm_usb_int=false, SofTermEnable=false, StringDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="String">\r\n      <Nodes>\r\n        <DescriptorNode Key="LANGID">\r\n          <m_value d6p1:type="StringZeroDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>4</bLength>\r\n            <wLANGID>1033</wLANGID>\r\n          </m_value>\r\n          <Value d6p1:type="StringZeroDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>4</bLength>\r\n            <wLANGID>1033</wLANGID>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor900">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>FreeDSP</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>FreeDSP</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor901">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>18</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Insanity</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>18</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Insanity</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor902">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>44</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Cypress Digital Audio</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>44</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Cypress Digital Audio</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor903">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>22</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Microphone</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>22</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Microphone</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor904">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>28</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>USB Streaming</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>28</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>USB Streaming</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor905">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>28</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Active 24 bit</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>28</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Active 24 bit</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor920">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Speaker</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Speaker</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor921">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>28</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Active 16 bit</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>28</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Active 16 bit</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor941">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>44</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>FreeDSP USB Interface</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>44</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>FreeDSP USB Interface</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n    <DescriptorNode Key="SpecialString">\r\n      <Nodes>\r\n        <DescriptorNode Key="Serial">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>2</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>2</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="EE">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MSFT100</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MSFT100</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, UINT_TYPE=uint8, VbusDetectTermEnable=false, VendorName=, Vid=04B4, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=USBFS_v3_0, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=USBFS, CY_INSTANCE_SHORT_NAME=USBFS, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 SP2, INSTANCE_NAME=USBFS, )
module USBFS_v3_0_1 (
    sof,
    vbusdet);
    output      sof;
    input       vbusdet;

    parameter epDMAautoOptimization = 0;

          wire  Net_1914;
          wire  Net_1915;
          wire  Net_1916;
          wire  Net_1917;
          wire  Net_1918;
          wire  Net_1919;
          wire [7:0] dma_request;
          wire  Net_1920;
          wire  Net_1921;
          wire  Net_1922;
          wire [7:0] Net_2039;
          wire  Net_2038;
          wire  Net_2037;
          wire  EPs_1_to_7_dma_complete;
          wire  Net_2036;
          wire  Net_2035;
          wire  Net_2034;
          wire  Net_2033;
          wire  Net_2032;
          wire  Net_2031;
          wire  Net_2030;
          wire  Net_2029;
          wire  Net_2028;
          wire  Net_2027;
          wire  Net_2026;
          wire  Net_2025;
          wire  Net_2024;
          wire [7:0] Net_1940;
          wire  Net_1939;
          wire  Net_1938;
          wire  Net_1937;
          wire  Net_1936;
          wire  Net_1935;
          wire  Net_1934;
          wire  Net_1933;
          wire  Net_1932;
          wire  Net_2047;
          wire  Net_1202;
          wire  dma_terminate;
          wire [7:0] Net_2040;
          wire  Net_1010;
    electrical  Net_1000;
    electrical  Net_597;
          wire  Net_1495;
          wire  Net_1498;
          wire  Net_1559;
          wire  Net_1567;
          wire  Net_1576;
          wire  Net_1579;
          wire  Net_1591;
          wire [7:0] dma_complete;
          wire  Net_1588;
          wire  Net_1876;
          wire [8:0] ep_int;
          wire  Net_1889;
          wire  busClk;
          wire  Net_95;


	cy_isr_v1_0
		#(.int_type(2'b10))
		dp_int
		 (.int_signal(Net_1010));


	wire [0:0] tmpOE__Dm_net;
	wire [0:0] tmpFB_0__Dm_net;
	wire [0:0] tmpIO_0__Dm_net;
	wire [0:0] tmpINTERRUPT_0__Dm_net;
	electrical [0:0] tmpSIOVREF__Dm_net;

	cy_psoc3_pins_v1_10
		#(.id("7641d554-b346-42e6-9fa8-7a9a58e6a340/8b77a6c4-10a0-4390-971c-672353e2a49c"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
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
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
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
		  .pin_mode("A"),
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
		  .spanning(1),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Dm
		 (.oe(tmpOE__Dm_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Dm_net[0:0]}),
		  .analog({Net_597}),
		  .io({tmpIO_0__Dm_net[0:0]}),
		  .siovref(tmpSIOVREF__Dm_net),
		  .interrupt({tmpINTERRUPT_0__Dm_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Dm_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Dp_net;
	wire [0:0] tmpFB_0__Dp_net;
	wire [0:0] tmpIO_0__Dp_net;
	electrical [0:0] tmpSIOVREF__Dp_net;

	cy_psoc3_pins_v1_10
		#(.id("7641d554-b346-42e6-9fa8-7a9a58e6a340/618a72fc-5ddd-4df5-958f-a3d55102db42"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b10),
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
		  .output_conn(1'b0),
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
		  .pin_mode("I"),
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
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Dp
		 (.oe(tmpOE__Dp_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Dp_net[0:0]}),
		  .analog({Net_1000}),
		  .io({tmpIO_0__Dp_net[0:0]}),
		  .siovref(tmpSIOVREF__Dp_net),
		  .interrupt({Net_1010}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Dp_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_psoc3_usb_v1_0 USB (
        .dp(Net_1000),
        .dm(Net_597),
        .sof_int(sof),
        .arb_int(Net_1889),
        .usb_int(Net_1876),
        .ept_int(ep_int[8:0]),
        .ord_int(Net_95),
        .dma_req(dma_request[7:0]),
        .dma_termin(dma_terminate));


	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_1
		 (.int_signal(ep_int[1]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_0
		 (.int_signal(ep_int[0]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		bus_reset
		 (.int_signal(Net_1876));



	cy_isr_v1_0
		#(.int_type(2'b10))
		arb_int
		 (.int_signal(Net_1889));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_6
		 (.int_signal(ep_int[6]));


	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign dma_complete[0] = Net_1922;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_1922));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign dma_complete[1] = Net_1921;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_1921));

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign dma_complete[2] = Net_1920;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_1920));

	// VirtualMux_4 (cy_virtualmux_v1_0)
	assign dma_complete[3] = Net_1919;

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_1919));

	// VirtualMux_5 (cy_virtualmux_v1_0)
	assign dma_complete[4] = Net_1918;

	// VirtualMux_6 (cy_virtualmux_v1_0)
	assign dma_complete[5] = Net_1917;

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_1918));

    ZeroTerminal ZeroTerminal_6 (
        .z(Net_1917));

	// VirtualMux_7 (cy_virtualmux_v1_0)
	assign dma_complete[6] = Net_1916;

	// VirtualMux_8 (cy_virtualmux_v1_0)
	assign dma_complete[7] = Net_1915;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_1916));

    ZeroTerminal ZeroTerminal_8 (
        .z(Net_1915));



endmodule

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

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

// I2S_v2_70(ClipPresent=false, ClockSyncMode=true, CommonClipThresholds=false, DataBits=24, Direction=2, EnableClipDetect=false, EnableRxByteSwap=false, EnableTxByteSwap=true, InterruptSource=0, NegThresholds=0u, 0u, 0u, 0u, 0u, NumRxChannels=0, NumRxLines=1, NumTxChannels=0, NumTxLines=1, PosThresholds=0, 0, 0, 0, 0, RxDataInterleaved=true, RxDataInterleaving=1, RxDMA_present=1, RxDmaPresent=false, RxInterruptSource=0, RxStsReg0Present=false, RxStsReg1Present=false, RxStsReg2Present=false, StaticBitResolution=true, TermVisibility_clip=false, TermVisibility_clock=true, TermVisibility_rx_dma0=false, TermVisibility_rx_dma1=false, TermVisibility_rx_interrupt=false, TermVisibility_sck=true, TermVisibility_sdi=false, TermVisibility_sdo=true, TermVisibility_tx_dma0=true, TermVisibility_tx_dma1=false, TermVisibility_tx_interrupt=true, TermVisibility_ws=true, TxDataInterleaved=true, TxDataInterleaving=1, TxDMA_present=1, TxDmaPresent=true, TxInterruptSource=0, TxStsReg0Present=true, TxStsReg1Present=false, TxStsReg2Present=false, WordSelect=64, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=I2S_v2_70, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=I2S_1, CY_INSTANCE_SHORT_NAME=I2S_1, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=70, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 SP2, INSTANCE_NAME=I2S_1, )
module I2S_v2_70_2 (
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
    defparam bI2S.DataBits = 24;
    defparam bI2S.Direction = 2;
    defparam bI2S.EnableClipDetect = 0;
    defparam bI2S.EnableRxByteSwap = 0;
    defparam bI2S.EnableTxByteSwap = 1;
    defparam bI2S.NumRxChannels = 0;
    defparam bI2S.NumTxChannels = 0;
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

// Component: B_SPI_Slave_v2_70
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_SPI_Slave_v2_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_SPI_Slave_v2_70\B_SPI_Slave_v2_70.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_SPI_Slave_v2_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_SPI_Slave_v2_70\B_SPI_Slave_v2_70.v"
`endif

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\3.3\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// SPI_Slave_v2_70(BidirectMode=false, ClockInternal=false, ControlFileName=SPI_Slave_Default.ctl, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CyGetRegReplacementString_1=CY_GET_REG8, CyGetRegReplacementString_2=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, DesiredBitRate=1000000, FixedPlacementEnabled=false, InternalInterruptEnabled=0, InternalRxInterruptEnabled=1, InternalTxInterruptEnabled=0, InterruptOnByteComplete=false, InterruptOnDone=false, InterruptOnRXEmpty=false, InterruptOnRXFull=false, InterruptOnRXNotEmpty=true, InterruptOnRXOverrun=false, InterruptOnTXEmpty=false, InterruptOnTXFull=false, InterruptOnTXNotFull=false, IntOnByteComp=0, IntOnRXEmpty=0, IntOnRXFull=0, IntOnRXNotEmpty=1, IntOnRXOver=0, IntOnSPIDone=0, IntOnTXEmpty=0, IntOnTXFull=0, IntOnTXNotFull=0, Mode=0, ModeUseZero=1, MultiSlaveEnable=false, NumberOfDataBits=8, PSoC3_ES2_PSoC5_ES1=false, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, RxBufferSize=4, ShiftDir=0, SiliconRevisionReplacementString=es3, TxBufferSize=4, UseInternalInterrupt=false, UseRxInternalInterrupt=true, UseTxInternalInterrupt=false, VerilogSectionReplacementString=sR8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=SPI_Slave_v2_70, CY_CONTROL_FILE=SPI_Slave_Default.ctl, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=SPIS, CY_INSTANCE_SHORT_NAME=SPIS, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=70, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 SP2, INSTANCE_NAME=SPIS, )
module SPI_Slave_v2_70_3 (
    ss,
    mosi,
    sclk,
    miso,
    clock,
    tx_interrupt,
    sdat,
    rx_interrupt,
    miso_oe,
    reset);
    input       ss;
    input       mosi;
    input       sclk;
    output      miso;
    input       clock;
    output      tx_interrupt;
    inout       sdat;
    output      rx_interrupt;
    output      miso_oe;
    input       reset;

    parameter NumberOfDataBits = 8;
    parameter ShiftDir = 0;

          wire  Net_177;
          wire  Net_176;
          wire  Net_81;
          wire  Net_75;
          wire  Net_169;
          wire  Net_182;

    B_SPI_Slave_v2_70 BSPIS (
        .mosi(Net_75),
        .sclk(sclk),
        .ss(ss),
        .miso(miso),
        .reset(reset),
        .clock(Net_81),
        .tx_interpt(tx_interrupt),
        .tx_enable(Net_182),
        .rx_interpt(rx_interrupt));
    defparam BSPIS.BidirectMode = 0;
    defparam BSPIS.ModeCPHA = 0;
    defparam BSPIS.ModePOL = 0;
    defparam BSPIS.NumberOfDataBits = 8;
    defparam BSPIS.ShiftDir = 0;


	cy_isr_v1_0
		#(.int_type(2'b10))
		RxInternalInterrupt
		 (.int_signal(rx_interrupt));


	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_75 = mosi;

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_81 = clock;


    assign miso_oe = ~ss;



endmodule

// top
module top ;

          wire  Net_608;
          wire  Net_772;
          wire  Net_579;
          wire  Net_569;
          wire  Net_746;
          wire  Net_745;
          wire  Net_744;
          wire  Net_743;
          wire  Net_732;
          wire  Net_731;
          wire  Net_730;
          wire  Net_742;
          wire  Net_618;
          wire [0:0] Net_719;
          wire  Net_718;
          wire  Net_717;
          wire [0:0] Net_716;
          wire [0:0] Net_561;
          wire [0:0] Net_715;
          wire [0:0] Net_714;
          wire [0:0] Net_521;
          wire  Net_520;
          wire  Net_519;
          wire [0:0] Net_713;
          wire  Net_517;
          wire  Net_516;
          wire  Net_771;
          wire  Net_770;
          wire  Net_411;
          wire  Net_410;
          wire  Net_409;
          wire  Net_408;
          wire  Net_407;
          wire  Net_573;
          wire  Net_340;
          wire  Net_339;
          wire  Net_337;
          wire  Net_419;
          wire  Net_338;

    SPI_Master_v2_50_0 SPIM (
        .mosi(Net_337),
        .sclk(Net_338),
        .ss(Net_339),
        .miso(Net_419),
        .clock(Net_340),
        .reset(Net_407),
        .rx_interrupt(Net_408),
        .sdat(Net_409),
        .tx_interrupt(Net_410));
    defparam SPIM.BidirectMode = 0;
    defparam SPIM.HighSpeedMode = 0;
    defparam SPIM.NumberOfDataBits = 8;
    defparam SPIM.ShiftDir = 0;


	cy_clock_v1_0
		#(.id("04740f1d-4c8d-4f0d-a342-aa7f8d15f889"),
		  .source_clock_id("CEF43CFB-0213-49b9-B980-2FFAB81C5B47"),
		  .divisor(0),
		  .period("1377410468.31956"),
		  .is_direct(0),
		  .is_digital(1))
		Clock
		 (.clock_out(Net_340));


	wire [0:0] tmpOE__SCLK_net;
	wire [0:0] tmpFB_0__SCLK_net;
	wire [0:0] tmpIO_0__SCLK_net;
	wire [0:0] tmpINTERRUPT_0__SCLK_net;
	electrical [0:0] tmpSIOVREF__SCLK_net;

	cy_psoc3_pins_v1_10
		#(.id("640f8e70-5666-4015-9ac8-6ed7f71d8e01"),
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
		SCLK
		 (.oe(tmpOE__SCLK_net),
		  .y({Net_338}),
		  .fb({tmpFB_0__SCLK_net[0:0]}),
		  .io({tmpIO_0__SCLK_net[0:0]}),
		  .siovref(tmpSIOVREF__SCLK_net),
		  .interrupt({tmpINTERRUPT_0__SCLK_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SCLK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_407));

    USBFS_v3_0_1 USBFS (
        .sof(Net_770),
        .vbusdet(1'b0));
    defparam USBFS.epDMAautoOptimization = 0;

	wire [0:0] tmpOE__SS_net;
	wire [0:0] tmpFB_0__SS_net;
	wire [0:0] tmpIO_0__SS_net;
	wire [0:0] tmpINTERRUPT_0__SS_net;
	electrical [0:0] tmpSIOVREF__SS_net;

	cy_psoc3_pins_v1_10
		#(.id("5ec2583b-d6a1-4a86-ac3e-b170e6f000fd"),
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
		SS
		 (.oe(tmpOE__SS_net),
		  .y({Net_339}),
		  .fb({tmpFB_0__SS_net[0:0]}),
		  .io({tmpIO_0__SS_net[0:0]}),
		  .siovref(tmpSIOVREF__SS_net),
		  .interrupt({tmpINTERRUPT_0__SS_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SS_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__MISO_net;
	wire [0:0] tmpIO_0__MISO_net;
	wire [0:0] tmpINTERRUPT_0__MISO_net;
	electrical [0:0] tmpSIOVREF__MISO_net;

	cy_psoc3_pins_v1_10
		#(.id("1425177d-0d0e-4468-8bcc-e638e5509a9b"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
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
		  .output_conn(1'b0),
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
		  .pin_mode("I"),
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
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		MISO
		 (.oe(tmpOE__MISO_net),
		  .y({1'b0}),
		  .fb({Net_419}),
		  .io({tmpIO_0__MISO_net[0:0]}),
		  .siovref(tmpSIOVREF__MISO_net),
		  .interrupt({tmpINTERRUPT_0__MISO_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__MISO_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__MOSI_net;
	wire [0:0] tmpFB_0__MOSI_net;
	wire [0:0] tmpIO_0__MOSI_net;
	wire [0:0] tmpINTERRUPT_0__MOSI_net;
	electrical [0:0] tmpSIOVREF__MOSI_net;

	cy_psoc3_pins_v1_10
		#(.id("ed092b9b-d398-4703-be89-cebf998501f6"),
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
		MOSI
		 (.oe(tmpOE__MOSI_net),
		  .y({Net_337}),
		  .fb({tmpFB_0__MOSI_net[0:0]}),
		  .io({tmpIO_0__MOSI_net[0:0]}),
		  .siovref(tmpSIOVREF__MOSI_net),
		  .interrupt({tmpINTERRUPT_0__MOSI_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__MOSI_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__DSP_reset_net;
	wire [0:0] tmpFB_0__DSP_reset_net;
	wire [0:0] tmpIO_0__DSP_reset_net;
	wire [0:0] tmpINTERRUPT_0__DSP_reset_net;
	electrical [0:0] tmpSIOVREF__DSP_reset_net;

	cy_psoc3_pins_v1_10
		#(.id("3daed191-30d6-4187-9f64-678a00de48cd"),
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
		  .output_conn(1'b0),
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
		DSP_reset
		 (.oe(tmpOE__DSP_reset_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__DSP_reset_net[0:0]}),
		  .io({tmpIO_0__DSP_reset_net[0:0]}),
		  .siovref(tmpSIOVREF__DSP_reset_net),
		  .interrupt({tmpINTERRUPT_0__DSP_reset_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__DSP_reset_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__GND_net;
	wire [0:0] tmpFB_0__GND_net;
	wire [0:0] tmpIO_0__GND_net;
	wire [0:0] tmpINTERRUPT_0__GND_net;
	electrical [0:0] tmpSIOVREF__GND_net;

	cy_psoc3_pins_v1_10
		#(.id("e851a3b9-efb8-48be-bbb8-b303b216c393"),
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
		GND
		 (.oe(tmpOE__GND_net),
		  .y({Net_516}),
		  .fb({tmpFB_0__GND_net[0:0]}),
		  .io({tmpIO_0__GND_net[0:0]}),
		  .siovref(tmpSIOVREF__GND_net),
		  .interrupt({tmpINTERRUPT_0__GND_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__GND_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    assign Net_516 = 1'h0;

    I2S_v2_70_2 I2S_1 (
        .clock(Net_517),
        .sdi(5'b0),
        .sck(Net_519),
        .ws(Net_520),
        .sdo(Net_521[0:0]),
        .rx_dma0(Net_714[0:0]),
        .rx_dma1(Net_715[0:0]),
        .tx_dma0(Net_561[0:0]),
        .tx_dma1(Net_716[0:0]),
        .rx_interrupt(Net_717),
        .tx_interrupt(Net_718),
        .clip(Net_719[0:0]));

	wire [0:0] tmpOE__I2S_SDATA_OUT_net;
	wire [0:0] tmpFB_0__I2S_SDATA_OUT_net;
	wire [0:0] tmpIO_0__I2S_SDATA_OUT_net;
	wire [0:0] tmpINTERRUPT_0__I2S_SDATA_OUT_net;
	electrical [0:0] tmpSIOVREF__I2S_SDATA_OUT_net;

	cy_psoc3_pins_v1_10
		#(.id("deffc43c-bce1-4506-b155-f4194afb784a"),
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
		I2S_SDATA_OUT
		 (.oe(tmpOE__I2S_SDATA_OUT_net),
		  .y({Net_521[0:0]}),
		  .fb({tmpFB_0__I2S_SDATA_OUT_net[0:0]}),
		  .io({tmpIO_0__I2S_SDATA_OUT_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_SDATA_OUT_net),
		  .interrupt({tmpINTERRUPT_0__I2S_SDATA_OUT_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_SDATA_OUT_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__I2S_BLCLK_net;
	wire [0:0] tmpFB_0__I2S_BLCLK_net;
	wire [0:0] tmpIO_0__I2S_BLCLK_net;
	wire [0:0] tmpINTERRUPT_0__I2S_BLCLK_net;
	electrical [0:0] tmpSIOVREF__I2S_BLCLK_net;

	cy_psoc3_pins_v1_10
		#(.id("c8e19693-67d9-4f29-a02f-cee5400c223a"),
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
		I2S_BLCLK
		 (.oe(tmpOE__I2S_BLCLK_net),
		  .y({Net_519}),
		  .fb({tmpFB_0__I2S_BLCLK_net[0:0]}),
		  .io({tmpIO_0__I2S_BLCLK_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_BLCLK_net),
		  .interrupt({tmpINTERRUPT_0__I2S_BLCLK_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_BLCLK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__I2S_LRCLK_net;
	wire [0:0] tmpFB_0__I2S_LRCLK_net;
	wire [0:0] tmpIO_0__I2S_LRCLK_net;
	wire [0:0] tmpINTERRUPT_0__I2S_LRCLK_net;
	electrical [0:0] tmpSIOVREF__I2S_LRCLK_net;

	cy_psoc3_pins_v1_10
		#(.id("0412e7a3-7bb2-4490-8a7d-0675b098c5ba"),
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
		I2S_LRCLK
		 (.oe(tmpOE__I2S_LRCLK_net),
		  .y({Net_520}),
		  .fb({tmpFB_0__I2S_LRCLK_net[0:0]}),
		  .io({tmpIO_0__I2S_LRCLK_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_LRCLK_net),
		  .interrupt({tmpINTERRUPT_0__I2S_LRCLK_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_LRCLK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("8c16417b-cea6-429e-9eb4-8d0321e8b8d4"),
		  .source_clock_id("39D5E4C2-EBFC-44ab-AE3D-19F9BBFD674D"),
		  .divisor(0),
		  .period("162760416.666667"),
		  .is_direct(0),
		  .is_digital(1))
		I2S_Clock
		 (.clock_out(Net_517));


	wire [0:0] tmpOE__MISO_S_net;
	wire [0:0] tmpFB_0__MISO_S_net;
	wire [0:0] tmpIO_0__MISO_S_net;
	wire [0:0] tmpINTERRUPT_0__MISO_S_net;
	electrical [0:0] tmpSIOVREF__MISO_S_net;

	cy_psoc3_pins_v1_10
		#(.id("0da5dade-7377-4971-87c9-f962b904b721"),
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
		MISO_S
		 (.oe(tmpOE__MISO_S_net),
		  .y({Net_742}),
		  .fb({tmpFB_0__MISO_S_net[0:0]}),
		  .io({tmpIO_0__MISO_S_net[0:0]}),
		  .siovref(tmpSIOVREF__MISO_S_net),
		  .interrupt({tmpINTERRUPT_0__MISO_S_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__MISO_S_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__MOSI_S_net;
	wire [0:0] tmpIO_0__MOSI_S_net;
	wire [0:0] tmpINTERRUPT_0__MOSI_S_net;
	electrical [0:0] tmpSIOVREF__MOSI_S_net;

	cy_psoc3_pins_v1_10
		#(.id("c828dd8a-0304-484a-b45c-f5531cc483a8"),
		  .drive_mode(3'b001),
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
		  .output_conn(1'b0),
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
		  .pin_mode("I"),
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
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		MOSI_S
		 (.oe(tmpOE__MOSI_S_net),
		  .y({1'b0}),
		  .fb({Net_730}),
		  .io({tmpIO_0__MOSI_S_net[0:0]}),
		  .siovref(tmpSIOVREF__MOSI_S_net),
		  .interrupt({tmpINTERRUPT_0__MOSI_S_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__MOSI_S_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__SCLK_S_net;
	wire [0:0] tmpIO_0__SCLK_S_net;
	wire [0:0] tmpINTERRUPT_0__SCLK_S_net;
	electrical [0:0] tmpSIOVREF__SCLK_S_net;

	cy_psoc3_pins_v1_10
		#(.id("83b2fde2-60ad-45b6-9e5c-cb3baa6e3f9a"),
		  .drive_mode(3'b001),
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
		  .output_conn(1'b0),
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
		  .pin_mode("I"),
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
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		SCLK_S
		 (.oe(tmpOE__SCLK_S_net),
		  .y({1'b0}),
		  .fb({Net_731}),
		  .io({tmpIO_0__SCLK_S_net[0:0]}),
		  .siovref(tmpSIOVREF__SCLK_S_net),
		  .interrupt({tmpINTERRUPT_0__SCLK_S_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SCLK_S_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    SPI_Slave_v2_70_3 SPIS (
        .mosi(Net_730),
        .sclk(Net_731),
        .ss(Net_732),
        .miso(Net_742),
        .clock(Net_573),
        .tx_interrupt(Net_743),
        .sdat(Net_744),
        .rx_interrupt(Net_745),
        .miso_oe(Net_746),
        .reset(Net_569));
    defparam SPIS.NumberOfDataBits = 8;
    defparam SPIS.ShiftDir = 0;

	wire [0:0] tmpOE__SS_S_net;
	wire [0:0] tmpIO_0__SS_S_net;
	wire [0:0] tmpINTERRUPT_0__SS_S_net;
	electrical [0:0] tmpSIOVREF__SS_S_net;

	cy_psoc3_pins_v1_10
		#(.id("cd950e03-7ab8-4043-a1a8-2fa7f791020e"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
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
		  .output_conn(1'b0),
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
		  .pin_mode("I"),
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
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		SS_S
		 (.oe(tmpOE__SS_S_net),
		  .y({1'b0}),
		  .fb({Net_732}),
		  .io({tmpIO_0__SS_S_net[0:0]}),
		  .siovref(tmpSIOVREF__SS_S_net),
		  .interrupt({tmpINTERRUPT_0__SS_S_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SS_S_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    assign Net_569 = 1'h0;


	cy_clock_v1_0
		#(.id("10c3a77c-06df-4921-bc9c-330653dd0624"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("2000000000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_SPISlave
		 (.clock_out(Net_573));


	wire [0:0] tmpOE__LED_net;
	wire [0:0] tmpFB_0__LED_net;
	wire [0:0] tmpIO_0__LED_net;
	wire [0:0] tmpINTERRUPT_0__LED_net;
	electrical [0:0] tmpSIOVREF__LED_net;

	cy_psoc3_pins_v1_10
		#(.id("19f0c780-d7a5-4425-9b92-ff050028e03e"),
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
		  .output_conn(1'b0),
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
		LED
		 (.oe(tmpOE__LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__LED_net[0:0]}),
		  .io({tmpIO_0__LED_net[0:0]}),
		  .siovref(tmpSIOVREF__LED_net),
		  .interrupt({tmpINTERRUPT_0__LED_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_dma_v1_0
		#(.drq_type(2'b01))
		TxDma
		 (.drq(Net_561[0:0]),
		  .trq(1'b0),
		  .nrq(Net_608));



	cy_isr_v1_0
		#(.int_type(2'b10))
		spi_rx_interrupt
		 (.int_signal(Net_745));



	cy_isr_v1_0
		#(.int_type(2'b10))
		DmaDone
		 (.int_signal(Net_608));




endmodule

