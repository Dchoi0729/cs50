// JS script for homepage website

let currentPage = "";

// When document is fully loaded
document.addEventListener('DOMContentLoaded', function() {

    setNavbar();

    // If current page is the home page
    if(currentPage == "Home"){
        // Center the maindiv top height and content element when window is resized
        window.addEventListener("resize", function(){
            vcenterElement(".maindiv");
            resizeContent();
        });

        // Center the content element(and hence, maindiv) when document is first loaded
        vcenterElement(".maindiv");
        resizeContent();
    }

    if(currentPage == "About"){
        vcenterElement(".map-cont");
    }

})

// Nav-bar related code (marks the current page of user + when hovered)
function setNavbar(){
    let navbarItems = document.querySelectorAll(".nav-link");

    underlineCurrent(navbarItems);

    navbarItems.forEach(function(item){
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
}

// Underlines current item of navbar
function underlineCurrent(navbarlist){
    navbarlist.forEach(function(item){
        if (item.ariaCurrent == "page"){
            currentPage = item.innerHTML;
            item.style.borderBottom = "3px solid white";
            item.style.color = "rgba(255,255,255,1)";
        }
    })
}

// Vertically centers the name object by manually setting top edge location
function vcenterElement(name){
    let vh = Math.max(document.documentElement.clientHeight || 0, window.innerHeight || 0);
    let elementHeight = Math.max(document.querySelector(name).offsetHeight, document.querySelector(name).scrollHeight);

    document.querySelector(name).style.top = (vh- elementHeight)/2 + "px";
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