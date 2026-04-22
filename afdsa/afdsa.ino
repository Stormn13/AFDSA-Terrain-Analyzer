#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "localhost";
const char* password = "12345678";

WebServer server(80);

#define IN1 25
#define IN2 26
#define IN3 27
#define IN4 33

// -------- MOTOR FUNCTIONS --------
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// -------- WEB PAGE --------
void handleRoot() {

  String html = "<html><head><meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<style>body{text-align:center;font-family:Arial;}button{padding:20px;font-size:20px;margin:5px;}</style>";
  html += "</head><body>";

  html += "<h2>ESP32 Robot Control</h2>";

  html += "<a href='/forward'><button>Forward</button></a><br>";
  html += "<a href='/left'><button>Left</button></a>";
  html += "<a href='/stop'><button>Stop</button></a>";
  html += "<a href='/right'><button>Right</button></a><br>";
  html += "<a href='/backward'><button>Backward</button></a>";

  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {

  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();

  WiFi.begin(ssid, password);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/forward", [](){ forward(); server.sendHeader("Location","/"); server.send(303); });
  server.on("/backward", [](){ backward(); server.sendHeader("Location","/"); server.send(303); });
  server.on("/left", [](){ left(); server.sendHeader("Location","/"); server.send(303); });
  server.on("/right", [](){ right(); server.sendHeader("Location","/"); server.send(303); });
  server.on("/stop", [](){ stopMotors(); server.sendHeader("Location","/"); server.send(303); });

  server.begin();
}

void loop() {
  server.handleClient();
}