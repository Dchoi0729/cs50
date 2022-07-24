// JS script for homepage website

// 1. Add JS script that resizes background for VH
// 2. Make all the hlper functions more userfriendly
// 3. Clean up the about.html format
// 4. Create the container for indiv carousel

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

    // If current page is the about page
    if(currentPage == "About"){

        resizeGrid();
        vcenterElement(".my-container");
        hcenterElement(".my-container");

        window.addEventListener("resize", function(){
            resizeGrid();
            vcenterElement(".my-container");
            hcenterElement(".my-container");
        });
    }

})

// Resizes the grid in about page
function resizeGrid(){
    let vw = Math.max(document.documentElement.clientWidth || 0, window.innerWidth || 0);

    let cont = document.querySelector(".my-container");
    cont.style.maxWidth = 0.9*vw + "px";
}

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

    console.log(vh);
    console.log(elementHeight);

    if(elementHeight < 340){
        elementHeight = 340;
    }
    console.log(elementHeight);

    if(elementHeight > 1000){
        document.querySelector(name).style.top = "200px";
        console.log(2);
    }
    else{
        document.querySelector(name).style.top = (vh- elementHeight)/2 + "px";
        console.log(1);
    }
}

// Horizontally centers the name object by manually setting left edge location
function hcenterElement(name){
    let vw = Math.max(document.documentElement.clientWidth || 0, window.innerWidth || 0);
    let elementWidth = Math.max(document.querySelector(name).offsetWidth);

    document.querySelector(name).style.left = (vw- elementWidth)/2 + "px";
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