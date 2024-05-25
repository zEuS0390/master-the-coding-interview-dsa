// const nemo = ['nemo'];
// const everyone = ['dory', 'bruce', 'marlin', 'nemo', 'gill', 'bloat', 'nigel', 'squirt', 'darla', 'hank'];
// const large = new Array(100000).fill('nemo');
// 
// function findNemo(array) {
// 	let t0 = performance.now();
// 	for (let i = 0; i < array.length; i++) {
// 		if (array[i] === 'nemo') {
// 			console.log('Found NEMO!');
// 		}
// 	}
// 	let t1 = performance.now();
// 	console.log('Call to find Nemo took ' + (t1 - t0) + ' milliseconds');
// }
// 
// findNemo(large);

const boxes = [0, 1, 2, 3, 4, 5];

function logFirstTwoBoxes(boxes) {
	console.log(boxes[0]);
	console.log(boxes[1]);
}

logFirstTwoBoxes(boxes);
