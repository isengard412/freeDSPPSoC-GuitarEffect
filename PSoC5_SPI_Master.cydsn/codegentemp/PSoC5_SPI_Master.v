// ======================================================================
// PSoC5_SPI_Master.v generated from TopDesign.cysch
// 05/13/2016 at 14:44
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
`define CYDEV_CHIP_MEMBER_4N 5
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 6
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 7
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 8
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 9
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 10
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 11
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4F 12
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4M 13
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 14
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 15
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4C 16
`define CYDEV_CHIP_REVISION_4C_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_MEMBER_5B 17
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 18
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 17
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

// SPI_Master_v2_50(BidirectMode=false, ClockInternal=false, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DesiredBitRate=500000, HighSpeedMode=false, InternalClockUsed=0, InternalInterruptEnabled=0, InternalRxInterruptEnabled=0, InternalTxInterruptEnabled=0, InterruptOnByteComplete=false, InterruptOnRXFull=false, InterruptOnRXNotEmpty=false, InterruptOnRXOverrun=false, InterruptOnSPIDone=false, InterruptOnSPIIdle=false, InterruptOnTXEmpty=false, InterruptOnTXNotFull=false, IntOnByteComp=0, IntOnRXFull=0, IntOnRXNotEmpty=0, IntOnRXOver=0, IntOnSPIDone=0, IntOnSPIIdle=0, IntOnTXEmpty=0, IntOnTXNotFull=0, Mode=1, ModeUseZero=1, NumberOfDataBits=16, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, RxBufferSize=4, ShiftDir=0, TxBufferSize=4, UseInternalInterrupt=false, UseRxInternalInterrupt=false, UseTxInternalInterrupt=false, VerilogSectionReplacementString=sR16, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=SPI_Master_v2_50, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=SPIM, CY_INSTANCE_SHORT_NAME=SPIM, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=50, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 SP1, INSTANCE_NAME=SPIM, )
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
    parameter NumberOfDataBits = 16;
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
    defparam BSPIM.ModeCPHA = 0;
    defparam BSPIM.ModePOL = 0;
    defparam BSPIM.NumberOfDataBits = 16;
    defparam BSPIM.ShiftDir = 0;

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_244 = miso;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_273 = Net_289;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_289));



endmodule

// USBFS_v3_0(AudioDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="Audio">\r\n      <Nodes />\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, CDCDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="CDC">\r\n      <Nodes>\r\n        <DescriptorNode Key="Interface847">\r\n          <m_value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>CDC Interface 1</DisplayName>\r\n          </m_value>\r\n          <Value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>CDC Interface 1</DisplayName>\r\n          </Value>\r\n          <Nodes>\r\n            <DescriptorNode Key="USBDescriptor848">\r\n              <m_value d8p1:type="CyCommunicationsInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>9</iwInterface>\r\n                <bInterfaceClass>2</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>0</bInterfaceNumber>\r\n                <bNumEndpoints>1</bNumEndpoints>\r\n                <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>2</iInterface>\r\n                <sInterface>CDC Communication Interface</sInterface>\r\n              </m_value>\r\n              <Value d8p1:type="CyCommunicationsInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>9</iwInterface>\r\n                <bInterfaceClass>2</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>0</bInterfaceNumber>\r\n                <bNumEndpoints>1</bNumEndpoints>\r\n                <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>2</iInterface>\r\n                <sInterface>CDC Communication Interface</sInterface>\r\n              </Value>\r\n              <Nodes>\r\n                <DescriptorNode Key="USBDescriptor850">\r\n                  <m_value d10p1:type="CyCDCHeaderDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>5</bLength>\r\n                    <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                    <bcdADC>272</bcdADC>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyCDCHeaderDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>5</bLength>\r\n                    <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                    <bcdADC>272</bcdADC>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor851">\r\n                  <m_value d10p1:type="CyCDCAbstractControlMgmtDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>4</bLength>\r\n                    <bDescriptorSubtype>ABSTRACT_CONTROL_MANAGEMENT</bDescriptorSubtype>\r\n                    <bmCapabilities>2</bmCapabilities>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyCDCAbstractControlMgmtDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>4</bLength>\r\n                    <bDescriptorSubtype>ABSTRACT_CONTROL_MANAGEMENT</bDescriptorSubtype>\r\n                    <bmCapabilities>2</bmCapabilities>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor852">\r\n                  <m_value d10p1:type="CyCDCUnionDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>5</bLength>\r\n                    <bDescriptorSubtype>UNION</bDescriptorSubtype>\r\n                    <bSubordinateInterface>AQ==</bSubordinateInterface>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyCDCUnionDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>5</bLength>\r\n                    <bDescriptorSubtype>UNION</bDescriptorSubtype>\r\n                    <bSubordinateInterface>AQ==</bSubordinateInterface>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor853">\r\n                  <m_value d10p1:type="CyCDCCallManagementDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>5</bLength>\r\n                    <bDescriptorSubtype>CALL_MANAGEMENT</bDescriptorSubtype>\r\n                    <bDataInterface>1</bDataInterface>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyCDCCallManagementDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>5</bLength>\r\n                    <bDescriptorSubtype>CALL_MANAGEMENT</bDescriptorSubtype>\r\n                    <bDataInterface>1</bDataInterface>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor854">\r\n                  <m_value d10p1:type="EndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bEndpointAddress>129</bEndpointAddress>\r\n                    <bmAttributes>3</bmAttributes>\r\n                  </m_value>\r\n                  <Value d10p1:type="EndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bEndpointAddress>129</bEndpointAddress>\r\n                    <bmAttributes>3</bmAttributes>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n              </Nodes>\r\n            </DescriptorNode>\r\n          </Nodes>\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="Interface855">\r\n          <m_value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>CDC Interface 2</DisplayName>\r\n          </m_value>\r\n          <Value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>CDC Interface 2</DisplayName>\r\n          </Value>\r\n          <Nodes>\r\n            <DescriptorNode Key="USBDescriptor856">\r\n              <m_value d8p1:type="CyDataInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>612</iwInterface>\r\n                <bInterfaceClass>10</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>1</bInterfaceNumber>\r\n                <bNumEndpoints>2</bNumEndpoints>\r\n                <bInterfaceSubClass>0</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>3</iInterface>\r\n                <sInterface>CDC Data Interface</sInterface>\r\n              </m_value>\r\n              <Value d8p1:type="CyDataInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>612</iwInterface>\r\n                <bInterfaceClass>10</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>1</bInterfaceNumber>\r\n                <bNumEndpoints>2</bNumEndpoints>\r\n                <bInterfaceSubClass>0</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>3</iInterface>\r\n                <sInterface>CDC Data Interface</sInterface>\r\n              </Value>\r\n              <Nodes>\r\n                <DescriptorNode Key="USBDescriptor858">\r\n                  <m_value d10p1:type="EndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bEndpointAddress>130</bEndpointAddress>\r\n                    <bmAttributes>2</bmAttributes>\r\n                    <wMaxPacketSize>64</wMaxPacketSize>\r\n                  </m_value>\r\n                  <Value d10p1:type="EndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bEndpointAddress>130</bEndpointAddress>\r\n                    <bmAttributes>2</bmAttributes>\r\n                    <wMaxPacketSize>64</wMaxPacketSize>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor859">\r\n                  <m_value d10p1:type="EndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bEndpointAddress>3</bEndpointAddress>\r\n                    <bmAttributes>2</bmAttributes>\r\n                    <wMaxPacketSize>64</wMaxPacketSize>\r\n                  </m_value>\r\n                  <Value d10p1:type="EndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bEndpointAddress>3</bEndpointAddress>\r\n                    <bmAttributes>2</bmAttributes>\r\n                    <wMaxPacketSize>64</wMaxPacketSize>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n              </Nodes>\r\n            </DescriptorNode>\r\n          </Nodes>\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, DeviceDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="Device">\r\n      <Nodes>\r\n        <DescriptorNode Key="USBDescriptor838">\r\n          <m_value d6p1:type="DeviceDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>DEVICE</bDescriptorType>\r\n            <bLength>18</bLength>\r\n            <iwManufacturer>7</iwManufacturer>\r\n            <iwProduct>613</iwProduct>\r\n            <sManufacturer>Cypress Semiconductor</sManufacturer>\r\n            <sProduct>SAR_SPIM_USB</sProduct>\r\n            <sSerialNumber />\r\n            <bDeviceClass>2</bDeviceClass>\r\n            <bDeviceSubClass>0</bDeviceSubClass>\r\n            <bDeviceProtocol>0</bDeviceProtocol>\r\n            <bMaxPacketSize0>0</bMaxPacketSize0>\r\n            <idVendor>1204</idVendor>\r\n            <idProduct>62002</idProduct>\r\n            <bcdDevice>1</bcdDevice>\r\n            <bcdUSB>512</bcdUSB>\r\n            <iManufacturer>1</iManufacturer>\r\n            <iProduct>4</iProduct>\r\n            <iSerialNumber>0</iSerialNumber>\r\n            <bNumConfigurations>1</bNumConfigurations>\r\n            <bMemoryMgmt>0</bMemoryMgmt>\r\n            <bMemoryAlloc>0</bMemoryAlloc>\r\n          </m_value>\r\n          <Value d6p1:type="DeviceDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>DEVICE</bDescriptorType>\r\n            <bLength>18</bLength>\r\n            <iwManufacturer>7</iwManufacturer>\r\n            <iwProduct>613</iwProduct>\r\n            <sManufacturer>Cypress Semiconductor</sManufacturer>\r\n            <sProduct>SAR_SPIM_USB</sProduct>\r\n            <sSerialNumber />\r\n            <bDeviceClass>2</bDeviceClass>\r\n            <bDeviceSubClass>0</bDeviceSubClass>\r\n            <bDeviceProtocol>0</bDeviceProtocol>\r\n            <bMaxPacketSize0>0</bMaxPacketSize0>\r\n            <idVendor>1204</idVendor>\r\n            <idProduct>62002</idProduct>\r\n            <bcdDevice>1</bcdDevice>\r\n            <bcdUSB>512</bcdUSB>\r\n            <iManufacturer>1</iManufacturer>\r\n            <iProduct>4</iProduct>\r\n            <iSerialNumber>0</iSerialNumber>\r\n            <bNumConfigurations>1</bNumConfigurations>\r\n            <bMemoryMgmt>0</bMemoryMgmt>\r\n            <bMemoryAlloc>0</bMemoryAlloc>\r\n          </Value>\r\n          <Nodes>\r\n            <DescriptorNode Key="USBDescriptor843">\r\n              <m_value d8p1:type="ConfigDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>CONFIGURATION</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwConfiguration>613</iwConfiguration>\r\n                <sConfiguration>SAR_SPIM_USB</sConfiguration>\r\n                <wTotalLength>67</wTotalLength>\r\n                <bNumInterfaces>2</bNumInterfaces>\r\n                <bConfigurationValue>0</bConfigurationValue>\r\n                <iConfiguration>4</iConfiguration>\r\n                <bmAttributes>192</bmAttributes>\r\n                <bMaxPower>50</bMaxPower>\r\n              </m_value>\r\n              <Value d8p1:type="ConfigDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>CONFIGURATION</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwConfiguration>613</iwConfiguration>\r\n                <sConfiguration>SAR_SPIM_USB</sConfiguration>\r\n                <wTotalLength>67</wTotalLength>\r\n                <bNumInterfaces>2</bNumInterfaces>\r\n                <bConfigurationValue>0</bConfigurationValue>\r\n                <iConfiguration>4</iConfiguration>\r\n                <bmAttributes>192</bmAttributes>\r\n                <bMaxPower>50</bMaxPower>\r\n              </Value>\r\n              <Nodes>\r\n                <DescriptorNode Key="Interface847">\r\n                  <m_value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>CDC Interface 1</DisplayName>\r\n                  </m_value>\r\n                  <Value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>CDC Interface 1</DisplayName>\r\n                  </Value>\r\n                  <Nodes>\r\n                    <DescriptorNode Key="USBDescriptor848">\r\n                      <m_value d12p1:type="CyCommunicationsInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>9</iwInterface>\r\n                        <bInterfaceClass>2</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>0</bInterfaceNumber>\r\n                        <bNumEndpoints>1</bNumEndpoints>\r\n                        <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>2</iInterface>\r\n                        <sInterface>CDC Communication Interface</sInterface>\r\n                      </m_value>\r\n                      <Value d12p1:type="CyCommunicationsInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>9</iwInterface>\r\n                        <bInterfaceClass>2</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>0</bInterfaceNumber>\r\n                        <bNumEndpoints>1</bNumEndpoints>\r\n                        <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>2</iInterface>\r\n                        <sInterface>CDC Communication Interface</sInterface>\r\n                      </Value>\r\n                      <Nodes>\r\n                        <DescriptorNode Key="USBDescriptor850">\r\n                          <m_value d14p1:type="CyCDCHeaderDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>5</bLength>\r\n                            <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                            <bcdADC>272</bcdADC>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyCDCHeaderDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>5</bLength>\r\n                            <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                            <bcdADC>272</bcdADC>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor851">\r\n                          <m_value d14p1:type="CyCDCAbstractControlMgmtDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>4</bLength>\r\n                            <bDescriptorSubtype>ABSTRACT_CONTROL_MANAGEMENT</bDescriptorSubtype>\r\n                            <bmCapabilities>2</bmCapabilities>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyCDCAbstractControlMgmtDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>4</bLength>\r\n                            <bDescriptorSubtype>ABSTRACT_CONTROL_MANAGEMENT</bDescriptorSubtype>\r\n                            <bmCapabilities>2</bmCapabilities>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor852">\r\n                          <m_value d14p1:type="CyCDCUnionDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>5</bLength>\r\n                            <bDescriptorSubtype>UNION</bDescriptorSubtype>\r\n                            <bSubordinateInterface>AQ==</bSubordinateInterface>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyCDCUnionDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>5</bLength>\r\n                            <bDescriptorSubtype>UNION</bDescriptorSubtype>\r\n                            <bSubordinateInterface>AQ==</bSubordinateInterface>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor853">\r\n                          <m_value d14p1:type="CyCDCCallManagementDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>5</bLength>\r\n                            <bDescriptorSubtype>CALL_MANAGEMENT</bDescriptorSubtype>\r\n                            <bDataInterface>1</bDataInterface>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyCDCCallManagementDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>5</bLength>\r\n                            <bDescriptorSubtype>CALL_MANAGEMENT</bDescriptorSubtype>\r\n                            <bDataInterface>1</bDataInterface>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor854">\r\n                          <m_value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bEndpointAddress>129</bEndpointAddress>\r\n                            <bmAttributes>3</bmAttributes>\r\n                          </m_value>\r\n                          <Value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bEndpointAddress>129</bEndpointAddress>\r\n                            <bmAttributes>3</bmAttributes>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                      </Nodes>\r\n                    </DescriptorNode>\r\n                  </Nodes>\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="Interface855">\r\n                  <m_value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>CDC Interface 2</DisplayName>\r\n                  </m_value>\r\n                  <Value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>CDC Interface 2</DisplayName>\r\n                  </Value>\r\n                  <Nodes>\r\n                    <DescriptorNode Key="USBDescriptor856">\r\n                      <m_value d12p1:type="CyDataInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>612</iwInterface>\r\n                        <bInterfaceClass>10</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>1</bInterfaceNumber>\r\n                        <bNumEndpoints>2</bNumEndpoints>\r\n                        <bInterfaceSubClass>0</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>3</iInterface>\r\n                        <sInterface>CDC Data Interface</sInterface>\r\n                      </m_value>\r\n                      <Value d12p1:type="CyDataInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>612</iwInterface>\r\n                        <bInterfaceClass>10</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>1</bInterfaceNumber>\r\n                        <bNumEndpoints>2</bNumEndpoints>\r\n                        <bInterfaceSubClass>0</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>3</iInterface>\r\n                        <sInterface>CDC Data Interface</sInterface>\r\n                      </Value>\r\n                      <Nodes>\r\n                        <DescriptorNode Key="USBDescriptor858">\r\n                          <m_value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bEndpointAddress>130</bEndpointAddress>\r\n                            <bmAttributes>2</bmAttributes>\r\n                            <wMaxPacketSize>64</wMaxPacketSize>\r\n                          </m_value>\r\n                          <Value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bEndpointAddress>130</bEndpointAddress>\r\n                            <bmAttributes>2</bmAttributes>\r\n                            <wMaxPacketSize>64</wMaxPacketSize>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor859">\r\n                          <m_value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bEndpointAddress>3</bEndpointAddress>\r\n                            <bmAttributes>2</bmAttributes>\r\n                            <wMaxPacketSize>64</wMaxPacketSize>\r\n                          </m_value>\r\n                          <Value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bEndpointAddress>3</bEndpointAddress>\r\n                            <bmAttributes>2</bmAttributes>\r\n                            <wMaxPacketSize>64</wMaxPacketSize>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                      </Nodes>\r\n                    </DescriptorNode>\r\n                  </Nodes>\r\n                </DescriptorNode>\r\n              </Nodes>\r\n            </DescriptorNode>\r\n          </Nodes>\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, DmaChannelPriority=3, DW_Hide_DmaAuto=true, DW_Hide_Usbv2Regs=true, DW_RegSize=8, DW_USB_CHGDET_CTRL=CR0, DW_USB_INTR_CAUSE_HI=CR0, DW_USB_INTR_CAUSE_LO=CR0, DW_USB_INTR_CAUSE_MED=CR0, DW_USB_INTR_LVL_SEL=CR0, DW_USB_INTR_SIE=CR0, DW_USB_INTR_SIE_MASK=CR0, DW_USB_LPM_CTRL=CR0, DW_USB_LPM_STAT=CR0, DW_USB_POWER_CTRL=CR0, EnableBatteryChargDetect=false, EnableCDCApi=true, EnableMidiApi=true, endpointMA=0, endpointMM=0, epDMAautoOptimization=false, extern_cls=false, extern_vbus=false, extern_vnd=false, extJackCount=0, Gen16bitEpAccessApi=true, HandleMscRequests=true, HIDReportDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="HIDReport">\r\n      <Nodes>\r\n        <DescriptorNode Key="USBDescriptor761">\r\n          <m_value d6p1:type="HIDReportDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>HID_REPORT</bDescriptorType>\r\n            <bLength>2</bLength>\r\n            <Name>3-Button Mouse</Name>\r\n            <wLength>50</wLength>\r\n          </m_value>\r\n          <Value d6p1:type="HIDReportDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>HID_REPORT</bDescriptorType>\r\n            <bLength>2</bLength>\r\n            <Name>3-Button Mouse</Name>\r\n            <wLength>50</wLength>\r\n          </Value>\r\n          <Nodes>\r\n            <DescriptorNode Key="USBDescriptor762">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="4" Type="USAGE_PAGE">\r\n                  <Value>\r\n                    <unsignedByte>5</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="4" Type="USAGE_PAGE">\r\n                  <Value>\r\n                    <unsignedByte>5</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor763">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>2</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>2</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor764">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="160" Type="COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>161</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="160" Type="COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>161</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor765">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor766">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="160" Type="COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>161</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="160" Type="COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>161</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor767">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="4" Type="USAGE_PAGE">\r\n                  <Value>\r\n                    <unsignedByte>5</unsignedByte>\r\n                    <unsignedByte>9</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="4" Type="USAGE_PAGE">\r\n                  <Value>\r\n                    <unsignedByte>5</unsignedByte>\r\n                    <unsignedByte>9</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor768">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="24" Type="USAGE_MINIMUM">\r\n                  <Value>\r\n                    <unsignedByte>25</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="24" Type="USAGE_MINIMUM">\r\n                  <Value>\r\n                    <unsignedByte>25</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor769">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="40" Type="USAGE_MAXIMUM">\r\n                  <Value>\r\n                    <unsignedByte>41</unsignedByte>\r\n                    <unsignedByte>3</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="40" Type="USAGE_MAXIMUM">\r\n                  <Value>\r\n                    <unsignedByte>41</unsignedByte>\r\n                    <unsignedByte>3</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor770">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="20" Type="LOGICAL_MINIMUM">\r\n                  <Value>\r\n                    <unsignedByte>21</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="20" Type="LOGICAL_MINIMUM">\r\n                  <Value>\r\n                    <unsignedByte>21</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor771">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="36" Type="LOGICAL_MAXIMUM">\r\n                  <Value>\r\n                    <unsignedByte>37</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="36" Type="LOGICAL_MAXIMUM">\r\n                  <Value>\r\n                    <unsignedByte>37</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor772">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="148" Type="REPORT_COUNT">\r\n                  <Value>\r\n                    <unsignedByte>149</unsignedByte>\r\n                    <unsignedByte>3</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="148" Type="REPORT_COUNT">\r\n                  <Value>\r\n                    <unsignedByte>149</unsignedByte>\r\n                    <unsignedByte>3</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor773">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="116" Type="REPORT_SIZE">\r\n                  <Value>\r\n                    <unsignedByte>117</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="116" Type="REPORT_SIZE">\r\n                  <Value>\r\n                    <unsignedByte>117</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor774">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="128" Type="INPUT">\r\n                  <Value>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>2</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Bits</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="128" Type="INPUT">\r\n                  <Value>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>2</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Bits</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor775">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="148" Type="REPORT_COUNT">\r\n                  <Value>\r\n                    <unsignedByte>149</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="148" Type="REPORT_COUNT">\r\n                  <Value>\r\n                    <unsignedByte>149</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor776">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="116" Type="REPORT_SIZE">\r\n                  <Value>\r\n                    <unsignedByte>117</unsignedByte>\r\n                    <unsignedByte>5</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="116" Type="REPORT_SIZE">\r\n                  <Value>\r\n                    <unsignedByte>117</unsignedByte>\r\n                    <unsignedByte>5</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor777">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="128" Type="INPUT">\r\n                  <Value>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Bits</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="128" Type="INPUT">\r\n                  <Value>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Bits</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor778">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="4" Type="USAGE_PAGE">\r\n                  <Value>\r\n                    <unsignedByte>5</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="4" Type="USAGE_PAGE">\r\n                  <Value>\r\n                    <unsignedByte>5</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor779">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>48</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>48</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor780">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>49</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>49</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor781">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="20" Type="LOGICAL_MINIMUM">\r\n                  <Value>\r\n                    <unsignedByte>21</unsignedByte>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="20" Type="LOGICAL_MINIMUM">\r\n                  <Value>\r\n                    <unsignedByte>21</unsignedByte>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor782">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="36" Type="LOGICAL_MAXIMUM">\r\n                  <Value>\r\n                    <unsignedByte>37</unsignedByte>\r\n                    <unsignedByte>127</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="36" Type="LOGICAL_MAXIMUM">\r\n                  <Value>\r\n                    <unsignedByte>37</unsignedByte>\r\n                    <unsignedByte>127</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor783">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="116" Type="REPORT_SIZE">\r\n                  <Value>\r\n                    <unsignedByte>117</unsignedByte>\r\n                    <unsignedByte>8</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="116" Type="REPORT_SIZE">\r\n                  <Value>\r\n                    <unsignedByte>117</unsignedByte>\r\n                    <unsignedByte>8</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor784">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="148" Type="REPORT_COUNT">\r\n                  <Value>\r\n                    <unsignedByte>149</unsignedByte>\r\n                    <unsignedByte>2</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="148" Type="REPORT_COUNT">\r\n                  <Value>\r\n                    <unsignedByte>149</unsignedByte>\r\n                    <unsignedByte>2</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor785">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="128" Type="INPUT">\r\n                  <Value>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>6</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Bits</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="128" Type="INPUT">\r\n                  <Value>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>6</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Bits</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor786">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="192" Type="END_COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>192</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>None</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="192" Type="END_COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>192</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>None</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor787">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="192" Type="END_COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>192</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>None</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="192" Type="END_COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>192</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>None</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n          </Nodes>\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, isrGroupArbiter=0, isrGroupBusReset=2, isrGroupEp0=1, isrGroupEp1=1, isrGroupEp2=1, isrGroupEp3=1, isrGroupEp4=1, isrGroupEp5=1, isrGroupEp6=1, isrGroupEp7=1, isrGroupEp8=1, isrGroupLpm=0, isrGroupSof=2, M0S8USBDSS_BLOCK_COUNT_1=0, max_interfaces_num=2, MidiDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="Midi">\r\n      <Nodes />\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, Mode=false, mon_vbus=false, MscDescriptors=, MscLogicalUnitsNum=1, out_sof=false, Pid=F232, powerpad_vbus=false, PRIMITIVE_INSTANCE=USB, ProdactName=, ProdactRevision=, REG_SIZE=reg8, RemoveDmaAutoOpt=true, RemoveVbusPin=true, rm_arb_int=false, rm_dma_1=true, rm_dma_2=true, rm_dma_3=true, rm_dma_4=true, rm_dma_5=true, rm_dma_6=true, rm_dma_7=true, rm_dma_8=true, rm_dp_int=false, rm_ep_isr_0=false, rm_ep_isr_1=false, rm_ep_isr_2=false, rm_ep_isr_3=false, rm_ep_isr_4=true, rm_ep_isr_5=true, rm_ep_isr_6=true, rm_ep_isr_7=true, rm_ep_isr_8=true, rm_lpm_int=true, rm_ord_int=false, rm_sof_int=false, rm_usb_int=false, SofTermEnable=false, StringDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="String">\r\n      <Nodes>\r\n        <DescriptorNode Key="LANGID">\r\n          <m_value d6p1:type="StringZeroDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>4</bLength>\r\n            <wLANGID>1033</wLANGID>\r\n          </m_value>\r\n          <Value d6p1:type="StringZeroDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>4</bLength>\r\n            <wLANGID>1033</wLANGID>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor7">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>44</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Cypress Semiconductor</bString>\r\n            <bUsed>true</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>44</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Cypress Semiconductor</bString>\r\n            <bUsed>true</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor9">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>56</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>CDC Communication Interface</bString>\r\n            <bUsed>true</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>56</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>CDC Communication Interface</bString>\r\n            <bUsed>true</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor612">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>38</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>CDC Data Interface</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>38</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>CDC Data Interface</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor613">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>26</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>SAR_SPIM_USB</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>26</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>SAR_SPIM_USB</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n    <DescriptorNode Key="SpecialString">\r\n      <Nodes>\r\n        <DescriptorNode Key="Serial">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>2</bLength>\r\n            <snType>SILICON_NUMBER</snType>\r\n            <bString />\r\n            <bUsed>true</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>2</bLength>\r\n            <snType>SILICON_NUMBER</snType>\r\n            <bString />\r\n            <bUsed>true</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="EE">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MSFT100</bString>\r\n            <bUsed>true</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MSFT100</bString>\r\n            <bUsed>true</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, UINT_TYPE=uint8, VbusDetectTermEnable=false, VendorName=, Vid=04B4, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=USBFS_v3_0, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=USBUART, CY_INSTANCE_SHORT_NAME=USBUART, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  3.3 SP1, INSTANCE_NAME=USBUART, )
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
		#(.id("c39ef993-d787-4c0c-8ad6-c0c81f866442/8b77a6c4-10a0-4390-971c-672353e2a49c"),
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
		#(.id("c39ef993-d787-4c0c-8ad6-c0c81f866442/618a72fc-5ddd-4df5-958f-a3d55102db42"),
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
		ord_int
		 (.int_signal(Net_95));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_3
		 (.int_signal(ep_int[3]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_2
		 (.int_signal(ep_int[2]));



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
		sof_int
		 (.int_signal(sof));


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

// top
module top ;

          wire  Net_413;
          wire  Net_412;
          wire  Net_411;
          wire  Net_410;
          wire  Net_409;
          wire  Net_408;
          wire  Net_407;
          wire  Net_340;
          wire  Net_337;
          wire  Net_419;
          wire  Net_338;
          wire  Net_339;

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
    defparam SPIM.NumberOfDataBits = 16;
    defparam SPIM.ShiftDir = 0;


	cy_clock_v1_0
		#(.id("04740f1d-4c8d-4f0d-a342-aa7f8d15f889"),
		  .source_clock_id("CEF43CFB-0213-49b9-B980-2FFAB81C5B47"),
		  .divisor(0),
		  .period("1000000000"),
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

    USBFS_v3_0_1 USBUART (
        .sof(Net_412),
        .vbusdet(1'b0));
    defparam USBUART.epDMAautoOptimization = 0;

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

	wire [0:0] tmpOE__Clock_out_net;
	wire [0:0] tmpFB_0__Clock_out_net;
	wire [0:0] tmpIO_0__Clock_out_net;
	wire [0:0] tmpINTERRUPT_0__Clock_out_net;
	electrical [0:0] tmpSIOVREF__Clock_out_net;

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
		Clock_out
		 (.oe(tmpOE__Clock_out_net),
		  .y({Net_340}),
		  .fb({tmpFB_0__Clock_out_net[0:0]}),
		  .io({tmpIO_0__Clock_out_net[0:0]}),
		  .siovref(tmpSIOVREF__Clock_out_net),
		  .interrupt({tmpINTERRUPT_0__Clock_out_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Clock_out_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};



endmodule

