#define first_trig 3
#define first_echo 2
#define second_trig 5
#define second_echo 4
#define third_trig 7
#define third_echo 6
#define fourth_trig 9
#define fourth_echo 8

void setup() {
  //OUTPUTS
  pinMode(first_trig, OUTPUT);
  pinMode(second_trig, OUTPUT);
  pinMode(third_trig, OUTPUT);
  pinMode(fourth_trig, OUTPUT); 

  //INPUTS
  pinMode(first_echo, INPUT);
  pinMode(second_echo, INPUT);
  pinMode(third_echo, INPUT);
  pinMode(fourth_echo, INPUT); 

  Serial.begin(9600);
}

void loop() {
  int arr[] = {calculateDistance(first_echo, first_trig), calculateDistance(second_echo, second_trig), calculateDistance(third_echo, third_trig), calculateDistance(fourth_echo, fourth_trig)};
  String order[] = {"first", "second", "third", "fourth"};
  int max_distance = arr[0];
  int max_order = 0;
  for(int i=0; i<4; i++) {
    if (max_distance < arr[i]) {
      max_distance = arr[i];
      max_order = i;
    }
  }

  Serial.print("The most distant sensor : ");
  Serial.print(order[max_order]);
  Serial.print("\n");
}

int calculateDistance(int echo, int trigger) {
  int timee, distance;

  digitalWrite(trigger, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger, LOW);

  timee = pulseIn(echo, HIGH);
  distance = (timee/2) / 29.1;
  
  return distance;  
}
