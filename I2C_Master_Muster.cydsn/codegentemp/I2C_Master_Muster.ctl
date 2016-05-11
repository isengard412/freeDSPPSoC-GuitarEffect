-- ======================================================================
-- I2C_Master_Muster.ctl generated from I2C_Master_Muster
-- 05/07/2016 at 14:54
-- This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
-- ======================================================================

-- TopDesign
-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-042 kit.
-- =============================================================================

-- === I2C master (SCB mode) ===
attribute port_location of \I2CM:scl(0)\ : label is "PORT(3,0)";
attribute port_location of \I2CM:sda(0)\ : label is "PORT(3,1)";

-- === RGB LED ===
attribute port_location of LED_RED(0)   : label is "PORT(1,6)";
attribute port_location of LED_GREEN(0) : label is "PORT(0,2)";

-- M0S8 Clock Editor
-- Directives Editor
-- Analog Device Editor
