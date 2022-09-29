import random
for i in range(20,100):
    temp=random.randint(1,100)
    humty=random.randint(1,100)
    print(temp)
    print(humty)
    
    if(temp>30):
       print("temperature is high")
       print("humidity is high")
       print("alaram on")
    else:
        print("alaram off")
