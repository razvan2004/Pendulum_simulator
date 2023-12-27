float data[];
int counter=1;
void setup()
{
  data=float(loadStrings("data.txt"));
  size(1000,1000);
  strokeWeight(5);
  fill(122);
}

void draw()
{
  
  if(counter<data[0])
  {
    delay(10);
    background(255);
    line(500,500,500+250*sin(data[counter]),500+250*cos(data[counter]));
    circle(500+250*sin(data[counter]),500+250*cos(data[counter]),20);
    counter++;
    
  }
}
