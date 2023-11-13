ThomasCSA : MultiOutUGen {

    var <>step;

	*kr { arg stepSize, b; 
		// Note the extra arg inserted so the UGen knows how many freqs to expect
		^this.multiNew('control', stepSize, b);
	}
	*ar { arg stepSize, b;
		// Note the extra arg inserted so the UGen knows how many freqs to expect
		^this.multiNew('audio', stepSize, b);
	}
	init { arg ... theInputs;
		inputs = theInputs;
		^this.initOutputs(3, rate);
	}
}
