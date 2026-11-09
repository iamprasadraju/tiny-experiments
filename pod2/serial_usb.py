
import usb.core
import usb.util

devices = usb.core.find(find_all=True, idVendor=0x2C7C)

for device in devices:
    print(f"\nDevice: {device.idVendor:04x}:{device.idProduct:04x}")

    try:
        print("Manufacturer:", usb.util.get_string(device, device.iManufacturer))
        print("Product:", usb.util.get_string(device, device.iProduct))
    except usb.core.USBError as error:
        print("String error:", error)

    for config in device:
        print(f"\nConfiguration: {config.bConfigurationValue}")

        for interface in config:
            print(
                f"Interface {interface.bInterfaceNumber}, "
                f"Alternate {interface.bAlternateSetting}, "
                f"Class={interface.bInterfaceClass:#04x}, "
                f"Subclass={interface.bInterfaceSubClass:#04x}, "
                f"Protocol={interface.bInterfaceProtocol:#04x}"
            )

            for endpoint in interface:
                print(
                    f"  Endpoint={endpoint.bEndpointAddress:#04x}, "
                    f"Attributes={endpoint.bmAttributes:#04x}, "
                    f"MaxPacketSize={endpoint.wMaxPacketSize}"
                )
