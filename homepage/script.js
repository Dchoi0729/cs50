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
})

function highlightCurrent(navbarlist){
    navbarlist.forEach(function(item){
        if (item.ariaCurrent == "page"){
            item.style.borderBottom = "3px solid white";
            item.style.color = "rgba(255,255,255,1)";
        }
    })
}