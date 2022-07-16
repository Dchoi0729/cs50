// When document is fully loaded
document.addEventListener('DOMContentLoaded', function() {
    let error = console.log(document.getElementById("error"))
    if(error != null){
        let myTimeout = setTimeout(myGreeting, 5000);
    }
})

function myStopFunction() {
    clearTimeout(myTimeout);
}