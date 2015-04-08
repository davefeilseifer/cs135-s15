
function validateForm() {
    var x = document.forms["myForm"]["fname"].value;
    if (x==null || x=="") {
        alert("First name must be filled out");
        return false;
    } else {
        alert("Hi " + x + " welcome to the world.");
	return true;
    }
}


// function validateForm2(){
//     var x = document.forms["myForm2"]["age"].value;
//     if(x < 0 || x > 100){
// 	alert("Your age must be between 0 and 100");
//     } else {
// 	alert("Thanks for telling me your age" + x);
//     }
// }

//document.getElementById("intro").innerHTML = "Name game";
