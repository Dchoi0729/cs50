// When document is fully loaded
document.addEventListener('DOMContentLoaded', function() {

    // Center the maindiv text height
    centerTextHeight();

    // Mark the current page the user is on
    let navbarItems = document.querySelectorAll("#navitem");
    navbarItems.forEach(function(item){

        highlightCurrent(navbarItems);

        item.addEventListener("mouseover", function(){
            navbarItems.forEach(function(tmpItem){
                tmpItem.style.borderBottom = "";

                if (tmpItem == item){
                    tmpItem.style.borderBottom = "3px solid white";
                }
            })
        })

        item.addEventListener("mouseleave", function(){
            item.style.borderBottom = "";
            highlightCurrent(navbarItems);
        })
    })


})

function highlightCurrent(navbarlist){
    navbarlist.forEach(function(item){
        if (item.ariaCurrent == "page"){
            item.style.borderBottom = "3px solid white";
            item.style.color = "rgba(255,255,255,1)";
        }
    })
}

function centerTextHeight(){
    let vh = Math.max(document.documentElement.clientHeight || 0, window.innerHeight || 0);
    let vw = Math.max(document.documentElement.clientWidth || 0, window.innerWidth || 0);

    let mainDivHeight = document.querySelector(".maindiv").offsetHeight;

    // Set the top edge location for the maindiv container
    document.querySelector(".maindiv").style.top = (vh- mainDivHeight)/2 + "px";

    let
    document.querySelector(".maindiv").style.top = (vh-mainDivh)/2 + "px";

    console.log(vw);
}