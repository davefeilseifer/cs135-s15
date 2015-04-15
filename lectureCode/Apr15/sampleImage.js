
var canvas = document.getElementById("map");
var context = canvas.getContext("2d");
context.fillStyle =  "rgb(0, 0, 255)";

for (var i = 0; i < 100; i++){
    for(var j = 0; j < 100; j++){
	context.fillRect(i, j, 1, 1);
    }
}

context.fillStyle =  "rgb(255, 0, 0)";
var x = 320;
var y = 240;


for (var i = 0; i < 200; i++){
    for(var j = 0; j < 100; j++){
	context.fillRect(x + i, y + j, 1, 1);
    }
}

	
