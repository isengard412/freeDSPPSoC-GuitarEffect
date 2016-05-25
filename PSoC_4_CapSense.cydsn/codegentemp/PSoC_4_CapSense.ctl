-- ======================================================================
-- PSoC_4_CapSense.ctl generated from PSoC_4_CapSense
-- 05/16/2016 at 21:40
-- This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
-- ======================================================================

-- TopDesign
-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-042 kit.
-- =============================================================================

-- === RGB LED ===
attribute port_location of LED_1(0) : label is "PORT(0,2)"; -- GREEN LED
attribute port_location of LED_2(0) : label is "PORT(0,3)"; -- BLUE LED

-- === Slider ===
attribute port_location of \CapSense_CSD:Cmod(0)\ : label is "PORT(4,2)";
attribute port_location of \CapSense_CSD:Sns(0)\ : label is "PORT(1,1)";
attribute port_location of \CapSense_CSD:Sns(1)\ : label is "PORT(1,2)";
attribute port_location of \CapSense_CSD:Sns(2)\ : label is "PORT(1,3)";
attribute port_location of \CapSense_CSD:Sns(3)\ : label is "PORT(1,4)";
attribute port_location of \CapSense_CSD:Sns(4)\ : label is "PORT(1,5)";

-- M0S8 Clock Editor
-- Directives Editor
-- Analog Device Editor
