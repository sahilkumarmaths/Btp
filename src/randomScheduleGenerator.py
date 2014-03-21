import random
import math

def randvec(vecsum, N, maxval, minval):
    if N*minval > vecsum or N*maxval < vecsum:
        raise ValueError ('Cannot create desired vector')

    indices = list(range(N))
    vec = [random.randint(minval,maxval) for i in indices]
    diff = sum(vec) - vecsum # we were off by this amount.

    while diff != 0:  
        addthis = 1 if diff > 0 else -1 # +/- 1 depending on if we were above or below target.
        diff -= addthis

        ### IMPLEMENTATION 1 ###
        idx = random.choice(indices) # Pick a random index to modify, check if it's OK to modify
        while not (minval < (vec[idx] - addthis) < maxval):  #operator chaining.  If you don't know it, look it up.  It's pretty cool.
            idx = random.choice(indices) #Not OK to modify.  Pick another.

        vec[idx] -= addthis #Update that index.

        ### IMPLEMENTATION 2 ###
        # random.shuffle(indices)
        # for idx in indices:
        #    if minval < (vec[idx] - addthis) < maxval:
        #        vec[idx]-=addthis
        #        break
        #
        # in situations where (based on choices of N, minval, maxval and vecsum)
        # many of the values in vec MUST BE minval or maxval, Implementation 2
        # may be superior.

    return vec

def newinput():
	
	processor=10
	id=1
	while processor<=5000:
		phases = 2
		while phases<processor/2:
			process = 10
			while process<=processor:
				print str(id)+" "+str(processor)+" "+str(phases)+" "+str(process)
				for i in range(0,phases):
					a = randvec(processor,process,processor,0)
					s=""
					for l in a:
						s+= str(l)+" "
					print s
				#processor=processor+5
				print
				id=id+1
				process=process+2
			phases=phases+2
		processor=processor+5

'''
def input1():
	phases = 10
	process = 10
	processor=10
	while processor<106:
		print str(processor/5-1)+" "+str(processor)+" "+str(phases)+" "+str(process)
		for i in range(0,phases):
			a = randvec(processor,process,processor,0)
			s=""
			for l in a:
				s+= str(l)+" "
			print s
		processor=processor+5
		print

#input1()

def input2():
	phases = 2
	process = 10
	processor=20
	while phases<=40:
		print str(phases/2)+" "+str(processor)+" "+str(phases)+" "+str(process)
		for i in range(0,phases):
			a = randvec(processor,process,processor,0)
			s=""
			for l in a:
				s+= str(l)+" "
			print s
		phases=phases+2
		print 

def input3():
	phases = 10
	process = 2
	processor=21
	while process<=21:
		print str(process-1)+" "+str(processor)+" "+str(phases)+" "+str(process)
		for i in range(0,phases):
			a = randvec(processor,process,processor,0)
			s=""
			for l in a:
				s+= str(l)+" "
			print s
		process=process+1
		print 
'''
newinput()
