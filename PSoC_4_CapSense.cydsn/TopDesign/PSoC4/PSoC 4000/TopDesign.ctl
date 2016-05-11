-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-040 kit.
-- =============================================================================

-- === RGB LED ===
attribute port_location of LED_1(0) : label is "PORT(1,1)"; -- GREEN LED

-- === Slider ===
attribute port_location of \CapSense_CSD:Cmod(0)\ : label is "PORT(0,4)";
attribute port_location of \CapSense_CSD:Sns(0)\ : label is "PORT(1,4)";
attribute port_location of \CapSense_CSD:Sns(1)\ : label is "PORT(1,5)";
attribute port_location of \CapSense_CSD:Sns(2)\ : label is "PORT(1,6)";
attribute port_location of \CapSense_CSD:Sns(3)\ : label is "PORT(1,0)";
attribute port_location of \CapSense_CSD:Sns(4)\ : label is "PORT(1,7)";