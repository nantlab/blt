import oscP5.*;
import netP5.*;

OscP5 oscP5;
NetAddress piLocation;

void setup() {
  size(400, 400);
  frameRate(25);
  oscP5 = new OscP5(this, 9000);
  piLocation = new NetAddress("192.168.178.5", 8000);
}

void mousePressed() {
  OscBundle bundle = new OscBundle();
  OscMessage message = new OscMessage("/tick");
  message.add(1.0);
  bundle.add(message);
  bundle.setTimetag(bundle.now() + 10000);
  oscP5.send(bundle, piLocation);
}