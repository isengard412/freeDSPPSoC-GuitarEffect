-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-042-BLE kit.
-- =============================================================================

-- === RGB LED ===
attribute port_location of LED_1(0) : label is "PORT(3,6)"; -- GREEN LED
attribute port_location of LED_2(0) : label is "PORT(3,7)"; -- BLUE LED

-- === Slider ===
attribute port_location of \CapSense_CSD:Cmod(0)\ : label is "PORT(4,0)";
attribute port_location of \CapSense_CSD:Sns(0)\ : label is "PORT(2,1)";
attribute port_location of \CapSense_CSD:Sns(1)\ : label is "PORT(2,2)";
attribute port_location of \CapSense_CSD:Sns(2)\ : label is "PORT(2,3)";
attribute port_location of \CapSense_CSD:Sns(3)\ : label is "PORT(2,4)";
attribute port_location of \CapSense_CSD:Sns(4)\ : label is "PORT(2,5)";