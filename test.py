def contactAdd(**kwargs):
  for x, (y, z) in kwargs.items():
    print("{} : {}, {}".format(x, y, z))

vars = {"ID & name" : (1, 'kim'), "phone num & email" : ('010-111-1111', 'lee@suu.ac.kr')}
#print(vars.)
contactAdd(**vars)