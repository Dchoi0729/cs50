// When document is fully loaded
document.addEventListener('DOMContentLoaded', function() {
    let error = document.getElementById("error")
    if(error != null){
        setTimeout(function(){ document.getElementById("error").innerHTML = "" }, 5000);
    }
})