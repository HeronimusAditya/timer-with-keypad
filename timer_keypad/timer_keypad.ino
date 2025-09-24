#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd(40, 42, 50, 48, 46, 44);

#define LED_GREEN 11
#define LED_YELLOW 10
#define LED_RED 9
#define BUZZER 8
#define BTN_START 7
#define BTN_PAUSE 6
#define BTN_RESET 5
#define BTN_CLEAR 4
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};
byte rowPins[ROWS] = {22, 24, 26, 28};
byte colPins[COLS] = {30, 32, 34, 36};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int setMinutes = 0;
int setSeconds = 0;
int countdownSeconds = 0;
bool isRunning = false;
bool isPaused = false;
bool isFinished = false;
bool hasBeenReset = false;
bool readyToClear = false;
unsigned long lastTick = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Input Timer:");
  lcd.setCursor(0, 1);
  lcd.print("Timer: 00:00");

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(BTN_START, INPUT);  // aktif HIGH
  pinMode(BTN_PAUSE, INPUT);
  pinMode(BTN_RESET, INPUT);
  pinMode(BTN_CLEAR, INPUT);

  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
}
void loop() {
  handleKeypad();
  handleButtons();
  handleTimer();
}
void handleKeypad() {
  static String input = "";
  char key = keypad.getKey();
  if (key) {
    if (key >= '0' && key <= '9') {
      input += key;
      lcd.setCursor(6, 1);
      lcd.print("    ");
      lcd.setCursor(6, 1);
      lcd.print(input);
      if (input.length() == 4) {
        setMinutes = input.substring(0, 2).toInt();
        setSeconds = input.substring(2, 4).toInt();
        countdownSeconds = setMinutes * 60 + setSeconds;
        if (countdownSeconds > 0) {
          displayTime(countdownSeconds);
          isFinished = false;
          hasBeenReset = false;
          readyToClear = false;
        }
        input = "";
      }
    } else if (key == '*') {
      input = "";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Input Time:");
      lcd.setCursor(0, 1);
      lcd.print("Time: 00:00");
    }
  }
}

void handleButtons() {
  if (digitalRead(BTN_RESET) == HIGH && isFinished) {
    countdownSeconds = setMinutes * 60 + setSeconds;
    isRunning = false;
    isPaused = false;
    isFinished = false;
    hasBeenReset = true;
    readyToClear = true;
    displayTime(countdownSeconds);
    noTone(BUZZER);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_RED, LOW);
    delay(300);
  }
  if (digitalRead(BTN_START) == HIGH && countdownSeconds > 0 && !isFinished) {
    isRunning = true;
    isPaused = false;
    digitalWrite(LED_GREEN, HIGH);
    delay(300);
  }
  if (digitalRead(BTN_PAUSE) == HIGH && isRunning) {
    isPaused = !isPaused;
    delay(300);
  }

  if (digitalRead(BTN_RESET) == HIGH && isPaused) {
    countdownSeconds = setMinutes * 60 + setSeconds;
    isRunning = false;
    isPaused = false;
    isFinished = false;
    hasBeenReset = true;
    readyToClear = true;
    displayTime(countdownSeconds);
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_RED, LOW);
    noTone(BUZZER);
    delay(500);
    digitalWrite(LED_YELLOW, LOW);
  }

  if (digitalRead(BTN_CLEAR) == HIGH && readyToClear) {
    countdownSeconds = 0;
    isRunning = false;
    isPaused = false;
    isFinished = false;
    hasBeenReset = false;
    readyToClear = false;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Input Time:");
    lcd.setCursor(0, 1);
    lcd.print("Time: 00:00");

    for (int i = 0; i < 2; i++) {
      digitalWrite(LED_RED, HIGH);
      delay(300);
      digitalWrite(LED_RED, LOW);
      delay(300);
    }

    noTone(BUZZER);
  }
}

void handleTimer() {
  if (isRunning && !isPaused && countdownSeconds > 0 && millis() - lastTick >= 1000) {
    lastTick = millis();
    countdownSeconds--;
    displayTime(countdownSeconds);
    if (countdownSeconds == 0) {
      isRunning = false;
      isFinished = true;
      displayTime(0);
      playHarryPotter();
    }
  }

  if (isPaused) {
    static bool blink = false;
    static unsigned long blinkTime = 0;
    if (millis() - blinkTime >= 500) {
      blinkTime = millis();
      blink = !blink;
      digitalWrite(LED_GREEN, blink ? HIGH : LOW);
    }
  }

  if (isFinished && countdownSeconds == 0) {
    static bool blink = false;
    static unsigned long blinkTime = 0;
    if (millis() - blinkTime >= 500) {
      blinkTime = millis();
      blink = !blink;
      digitalWrite(LED_GREEN, blink ? HIGH : LOW);
      digitalWrite(LED_YELLOW, blink ? HIGH : LOW);
      digitalWrite(LED_RED, blink ? HIGH : LOW);
    }
  }
}

void displayTime(int totalSeconds) {
  int minutes = totalSeconds / 60;
  int seconds = totalSeconds % 60;
  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
}

void playHarryPotter() {
  int melody[] = {
    659, 622, 659, 622, 659, 494, 587, 523, 440, 494,
    523, 587, 659, 622, 659, 622, 659, 494, 587, 523
  };

  int durations[] = {
    300, 300, 300, 300, 300, 400, 400, 400, 400, 400,
    400, 400, 300, 300, 300, 300, 300, 400, 400, 400
  };

  for (int i = 0; i < sizeof(melody) / sizeof(int); i++) {
    tone(BUZZER, melody[i], durations[i]);
    delay(durations[i] + 50);
  }
}
