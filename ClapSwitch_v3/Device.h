class Device {
private:
  const uint8_t needClaps;
  const String name;
  const uint8_t pin;

public:
  Device(uint8_t needClapsParam, String nameParam, uint8_t pinParam) 
    :needClaps(needClapsParam), name(nameParam), pin(pinParam) {}

  uint8_t getNeedClaps() {
    return needClaps;
  }

  uint8_t getPin() {
    return pin;
  }
};