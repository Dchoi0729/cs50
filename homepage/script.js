// When document is fully loaded
document.addEventListener('DOMContentLoaded', function() {

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

    console.log(document.querySelector("#navbar").offsetHeight);
    let vh = Math.max(document.documentElement.clientHeight || 0, window.innerHeight || 0)
    console.log(vh - document.querySelector("#navbar").offsetHeight);
    document.querySelector(".maindiv").style.top = document.querySelector("#navbar").offsetHeight + 10;
    document.querySelector(".maindiv").style.height = vh - document.querySelector("#navbar").offsetHeight;
})

function highlightCurrent(navbarlist){
    navbarlist.forEach(function(item){
        if (item.ariaCurrent == "page"){
            item.style.borderBottom = "3px solid white";
            item.style.color = "rgba(255,255,255,1)";
        }
    })
}