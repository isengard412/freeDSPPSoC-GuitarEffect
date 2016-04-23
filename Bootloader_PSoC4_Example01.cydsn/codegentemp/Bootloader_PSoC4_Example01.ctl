-- ======================================================================
-- Bootloader_PSoC4_Example01.ctl generated from Bootloader_PSoC4_Example01
-- 04/20/2016 at 18:13
-- This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
-- ======================================================================

-- TopDesign
-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-042 kit.
-- =============================================================================

-- === I2C ===
attribute port_location of \I2C_Slave:scl(0)\ : label is "PORT(3,0)";
attribute port_location of \I2C_Slave:sda(0)\ : label is "PORT(3,1)";

-- === RGB LED ===
attribute port_location of Bootloader_Status(0) : label is "PORT(0,3)"; -- BLUE LED


-- M0S8 Clock Editor
-- Directives Editor
-- Analog Device Editor
