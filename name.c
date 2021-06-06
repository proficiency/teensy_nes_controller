#include <usb_names.h>

#define MANUFACTURER_NAME          \
	{                          \
		'p', 'r', 'o', 'f', 'i', 'c', 'i', 'e', 'n', 'c', 'y' \
	}
#define MANUFACTURER_NAME_LEN 12

#define PRODUCT_NAME                                                            \
	{                                                                       \
		'N', 'E', 'S', ' ', 'C', 'o', 'n', 't', 'r', 'o', 'l', 'l', 'e', 'r' \
	}
#define PRODUCT_NAME_LEN 14

struct usb_string_descriptor_struct usb_string_manufacturer_name = {
	2 + MANUFACTURER_NAME_LEN * 2,
	3,
	MANUFACTURER_NAME};

struct usb_string_descriptor_struct usb_string_product_name = {
	2 + PRODUCT_NAME_LEN * 2,
	3,
	PRODUCT_NAME};