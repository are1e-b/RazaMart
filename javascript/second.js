// marks
let marks=[85,97,44,37,76,60]
let sum=0;
for(let i=0;i<marks.length;i++){
    console.log(marks[i]);
    sum+=marks[i];
    
}
let avg=sum/marks.length;
console.log(avg);


// price
let price=[250,180,260,290,350,400];
let new_array=[];
for(let i=1;i<=price.length;i++){
    let discount=price[i]-(price[i]/10);
   new_array.push[discount];
}
console.log(new_array);

