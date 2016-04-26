-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-046 kit.
-- =============================================================================

-- === I2C master (SCB mode) ===
attribute port_location of \I2CM:scl(0)\ : label is "PORT(4,0)";
attribute port_location of \I2CM:sda(0)\ : label is "PORT(4,1)";

-- === RGB LED ===
attribute port_location of LED_RED(0) : label is "PORT(5,2)"; -- RED LED
attribute port_location of LED_GREEN(0) : label is "PORT(5,3)"; -- GREEN LED
attribute port_location of REPLACE_WITH_ACTUAL_PIN_NAME(0) : label is "PORT(5,4)"; -- BLUE LED

