// When document is fully loaded
document.addEventListener('DOMContentLoaded', function() {

    // Center the maindiv top height and content element when window is resized
    window.addEventListener("resize", centerText);

    // Center the content element(and hence, maindiv) when document is first loaded
    resizeContent();

    // Mark the current page the user is on
    let navbarItems = document.querySelectorAll(".nav-link");
    navbarItems.forEach(function(item){

        underlineCurrent(navbarItems);

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
            underlineCurrent(navbarItems);
        })
    })
})

// Underlines current item of navbar
function underlineCurrent(navbarlist){
    navbarlist.forEach(function(item){
        if (item.ariaCurrent == "page"){
            item.style.borderBottom = "3px solid white";
            item.style.color = "rgba(255,255,255,1)";
        }
    })
}

// Centers the maindiv text in index.html
function centerText(){
    let vh = Math.max(document.documentElement.clientHeight || 0, window.innerHeight || 0);
    let mainDivHeight = document.querySelector(".maindiv").offsetHeight;

    // Set the top edge location for the maindiv container
    document.querySelector(".maindiv").style.top = (vh- mainDivHeight)/2 + "px";

    resizeContent();
}

// Correctly sizes the content element
function resizeContent(){
    let vw = Math.max(document.documentElement.clientWidth || 0, window.innerWidth || 0);

    if (0.3*vw > 250){
        document.querySelector(".content").style.width =  "30vw";
        document.querySelector(".content").style.fontSize = "5vw";
    }
    else{
        document.querySelector(".content").style.width =  "250px";
        document.querySelector(".content").style.fontSize = "41.6px";
    }
}