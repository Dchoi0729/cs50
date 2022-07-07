// When document is fully loaded
document.addEventListener('DOMContentLoaded', function() {

    // Center the maindiv text height when window is resized
    window.addEventListener("resize", centerText);

    // Center the maindiv text for the first time
    centerText();

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

function centerText(){
    let vh = Math.max(document.documentElement.clientHeight || 0, window.innerHeight || 0);
    let vw = Math.max(document.documentElement.clientWidth || 0, window.innerWidth || 0);

    let mainDivHeight = document.querySelector(".maindiv").offsetHeight;

    console.log(vh);
    console.log(mainDivHeight);
    console.log(document.querySelector(".maindiv").offsetHeight);
    console.log((vh- mainDivHeight)/2);

    setTimeout(() => {
        console.log(document.querySelector(".maindiv").offsetHeight);
    }, 300);

    // Set the top edge location for the maindiv container
    document.querySelector(".maindiv").style.top = (vh- mainDivHeight)/2 + "px";

    // Set appropriate width and font size for the content div
    let contentWidth = Math.max(250 , 0.3*vw);
    if (0.3*vw > 250){
        document.querySelector(".content").style.width =  "30vw";
        document.querySelector(".content").style.fontSize = "5vw";
    }
    else{
        document.querySelector(".content").style.width =  "250px";
        document.querySelector(".content").style.fontSize = "41.6px";
    }
}