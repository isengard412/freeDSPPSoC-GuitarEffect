-- ======================================================================
-- PSoC4_I2C_Slave.ctl generated from PSoC4_I2C_Slave
-- 07/12/2016 at 20:15
-- This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
-- ======================================================================

-- TopDesign
-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-042 kit.
-- =============================================================================

-- === I2C slave (SCB mode) ===
attribute port_location of \I2CS:scl(0)\ : label is "PORT(3,0)";
attribute port_location of \I2CS:sda(0)\ : label is "PORT(3,1)";

-- === RGB LED ===
attribute port_location of LED_RED(0)   : label is "PORT(1,6)";
attribute port_location of LED_GREEN(0) : label is "PORT(0,2)";
attribute port_location of LED_BLUE(0)  : label is "PORT(0,3)";

-- M0S8 Clock Editor
-- Directives Editor
-- Analog Device Editor
