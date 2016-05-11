-- ======================================================================
-- USBFS_UART01_Example.ctl generated from USBFS_UART01_Example
-- 05/11/2016 at 17:57
-- This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
-- ======================================================================

-- I2CS

-- TopDesign
-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-030 kit.
-- =============================================================================

-- === USBFS ===
attribute port_location of \USBUART:Dp(0)\   : label is "PORT(15,6)";
attribute port_location of \USBUART:Dm(0)\   : label is "PORT(15,7)";


-- === LCD ===
attribute port_location of \LCD:LCDPort(0)   : label is "PORT(2,0)";

-- PSoC3/5 Clock Editor
-- Directives Editor
-- Analog Device Editor
