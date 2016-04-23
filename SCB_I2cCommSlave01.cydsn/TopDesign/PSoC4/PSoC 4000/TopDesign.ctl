-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-040 kit.
-- =============================================================================

-- === I2C slave (SCB mode) ===
attribute port_location of \I2CS:scl(0)\ : label is "PORT(1,2)";
attribute port_location of \I2CS:sda(0)\ : label is "PORT(1,3)";

-- === RGB LED ===
attribute port_location of LED_RED(0)   : label is "PORT(3,2)";
attribute port_location of LED_GREEN(0) : label is "PORT(1,1)";
attribute port_location of LED_BLUE(0)  : label is "PORT(0,2)";

