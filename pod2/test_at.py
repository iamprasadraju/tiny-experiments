
import serial
import time

PORT = "/dev/cu.usbmodem00006"
BAUDRATE = 115200

def send_at(ser, command):
    print(f"\n>>> {command}")

    ser.write((command + "\r\n").encode("ascii"))
    ser.flush()

    time.sleep(1)

    response = ser.read_all().decode("utf-8", errors="replace")
    print(response if response else "[No response]")


def main():
    try:
        with serial.Serial(
            PORT,
            BAUDRATE,
            timeout=1,
            write_timeout=2,
        ) as ser:

            print(f"Connected to {PORT}")

            time.sleep(2)
            ser.reset_input_buffer()

            for command in [
                "AT",
                "ATI",
                "AT+GMR",
            ]:
                send_at(ser, command)

    except serial.SerialException as exc:
        print(f"Serial error: {exc}")


if __name__ == "__main__":
    main()
